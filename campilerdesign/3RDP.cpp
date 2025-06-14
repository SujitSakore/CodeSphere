//vi RDP.cpp
//gcc RDP.cpp -o abcrdp
// ./abcrdp


#include <bits/stdc++.h>
using namespace std;

vector<pair<string, vector<string>>> grammar;
vector<string> inputTokens;
int pos = 0;
vector<string> splitProduction(string s) {
    vector<string> result;
    stringstream ss(s);
    string sym;
    while (ss >> sym)
        result.push_back(sym);
    return result;
}
void removeLeftRecursion()
{
    vector<pair<string, vector<string>>> newGrammar;
    for(int i = 0; i < grammar.size(); i++)
    {
        string Ai = grammar[i].first;
        vector<string> Ai_prods = grammar[i].second;
        for(int j = 0; j < i; j++)
        {
            string Aj = grammar[j].first;
            vector<string> Aj_prods = grammar[j].second;

            vector<string> updatedProds;
            for (auto& prod : Ai_prods)
            {
                vector<string> symbols = splitProduction(prod);
                if(!symbols.empty() && symbols[0] == Aj)
                {
                    for(auto& delta : Aj_prods)
                    {
                        string newProd = delta;
                        for (int k = 1; k < symbols.size(); k++)
                            newProd += " " + symbols[k];
                        updatedProds.push_back(newProd);
                    }
                }
                else
                {
                    updatedProds.push_back(prod);
                }
            }
            Ai_prods = updatedProds;
        }
 vector<string> alpha, beta;
        for(auto& prod : Ai_prods)
        {
            vector<string> symbols = splitProduction(prod);
            if(!symbols.empty() && symbols[0] == Ai)//there exists pr as Ai -> Ai alpha
            {
                string suffix;
                for(int k = 1; k < symbols.size(); k++)
                    suffix += symbols[k] + " ";
                alpha.push_back(suffix);
            }
            else
            {
                string full;
                for(auto& sym : symbols)
                    full += sym + " ";

                beta.push_back(full);
            }
        }
        if (alpha.empty())
        newGrammar.push_back({ Ai, Ai_prods });
        else{
            string Ai_dash = Ai + "'";
            vector<string> newAiProds;
            for(auto& b : beta)
                newAiProds.push_back(b + " " + Ai_dash);

            vector<string> AiDashProds;
            for(auto& a : alpha)
                AiDashProds.push_back(a + " " + Ai_dash);
            AiDashProds.push_back("ε");

            newGrammar.push_back({ Ai, newAiProds });
            newGrammar.push_back({ Ai_dash, AiDashProds });
        }
    }
grammar = newGrammar;
}

vector<string> getProductionsFor(string nt) {
for (auto& rule : grammar)
if (rule.first == nt)
return rule.second;
return {};
}
bool match(string t) {
    if (pos < inputTokens.size() && inputTokens[pos] == t) {
        pos++;
        return true;
    }
    return false;
}
map<string, function<bool()>> parseFns;
bool parseNonTerminal(string nt) {
    vector<string> productions = getProductionsFor(nt);
    for (string prod : productions) {
        int startPos = pos;
        vector<string> symbols = splitProduction(prod);
        bool success = true;
        vector<string> trace;
        for (string sym : symbols) {
            if (sym == "ε") continue;

            if (parseFns.count(sym)) {
                // Non-terminal
                if (!parseFns[sym]()) {
                    success = false;
                    break;
                }
            } else {
                // Terminal
                if (!match(sym)) {
                    success = false;
                    break;
                }
            }
        }
        if (success) {
            cout << nt << " -> " << prod << endl;
            return true;
        } else {
            pos = startPos;
        }
    }

    return false;
}
int main() {
    grammar.clear();
    int n;
    cout << "Enter number of production rules: ";
    cin >> n;
    cin.ignore();
    while (n--) {
        string head, body;
        cout << "Enter head: ";
        getline(cin, head);
        cout << "Enter body (space-separated): ";
        getline(cin, body);

        bool found = false;
        for (auto& rule : grammar) {
            if (rule.first == head) {
                rule.second.push_back(body);
                found = true;
                break;
            }
        }
        if (!found)
            grammar.push_back({ head, { body } });
    }
    removeLeftRecursion();
    string inputLine;
    cout << "\nEnter input string (space-separated): ";
    getline(cin, inputLine);
    stringstream ss(inputLine);
    string token;
    while (ss >> token)
       inputTokens.push_back(token);
    for (auto& rule : grammar) {
        string nt = rule.first;
        parseFns[nt] = [nt]() { return parseNonTerminal(nt); };
    }

    cout << "\nParsing steps:\n";
    bool result = parseFns[grammar[0].first]() && pos == inputTokens.size();

    if (result)
        cout << "\nInput string ACCEPTED\n";
    else
        cout << "\nInput string REJECTED\n";

    return 0;
}
