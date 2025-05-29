//g++ remove_left_recursion.cpp -o abcrlr
//./abcrlr

//input

//Enter number of non-terminals: 3
// Enter production for non-terminal 1 (e.g., A->A a | b): E->E + T | T
// Enter production for non-terminal 2 (e.g., A->A a | b): T->T * F | F
// Enter production for non-terminal 3 (e.g., A->A a | b): F->( E ) | id

//output

// Grammar after removing left recursion:
// E -> T E'
// E' -> + T E' | e
// T -> F T'
// T' -> * F T' | e
// F -> ( E )  |  id


#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>

using namespace std;

// Grammar: each production is a pair of head and body (multiple productions)
vector<pair<string, vector<string>>> grammar;

// Utility to split a production string into individual symbols
vector<string> splitProduction(const string& production) {
    vector<string> symbols;
    stringstream ss(production);
    string symbol;
    while (ss >> symbol)
        symbols.push_back(symbol);
    return symbols;
}

// Function to remove both indirect and immediate left recursion
void removeLeftRecursion() {
    vector<pair<string, vector<string>>> newGrammar;

    for (int i = 0; i < grammar.size(); i++) {
        string Ai = grammar[i].first;
        vector<string> Ai_prods = grammar[i].second;

        // Step 1: Handle indirect left recursion
        for (int j = 0; j < i; j++) {
            string Aj = grammar[j].first;
            vector<string> Aj_prods = grammar[j].second;

            vector<string> updatedProds;
            for (auto& prod : Ai_prods) {
                vector<string> symbols = splitProduction(prod);
                if (!symbols.empty() && symbols[0] == Aj) {
                    for (auto& delta : Aj_prods) {
                        string newProd = delta;
                        for (int k = 1; k < symbols.size(); k++)
                            newProd += " " + symbols[k];
                        updatedProds.push_back(newProd);
                    }
                } else {
                    updatedProds.push_back(prod);
                }
            }
            Ai_prods = updatedProds;
        }

        // Step 2: Eliminate immediate left recursion
        vector<string> alpha, beta;
        for (auto& prod : Ai_prods) {
            vector<string> symbols = splitProduction(prod);
            if (!symbols.empty() && symbols[0] == Ai) {
                string suffix;
                for (int k = 1; k < symbols.size(); k++)
                    suffix += symbols[k] + " ";
                alpha.push_back(suffix);
            } else {
                string full;
                for (auto& sym : symbols)
                    full += sym + " ";
                beta.push_back(full);
            }
        }

        if (alpha.empty()) {
            newGrammar.push_back({ Ai, Ai_prods });
        } else {
            string Ai_dash = Ai + "'";
            vector<string> newAiProds, AiDashProds;

            for (auto& b : beta)
                newAiProds.push_back(b + Ai_dash);

            for (auto& a : alpha)
                AiDashProds.push_back(a + Ai_dash);
            AiDashProds.push_back("e");

            newGrammar.push_back({ Ai, newAiProds });
            newGrammar.push_back({ Ai_dash, AiDashProds });
        }
    }

    grammar = newGrammar;

    // Output transformed grammar
    cout << "\nGrammar after removing left recursion:\n";
    for (auto& rule : grammar) {
        cout << rule.first << " -> ";
        for (int i = 0; i < rule.second.size(); ++i) {
            cout << rule.second[i];
            if (i != rule.second.size() - 1)
                cout << " | ";
        }
        cout << endl;
    }
}

// Main function
int main() {
    int n;
    cout << "Enter number of non-terminals: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string input;
        cout << "Enter production for non-terminal " << (i + 1) << " (e.g., A->A a | b): ";
        getline(cin, input);

        size_t arrowPos = input.find("->");
        if (arrowPos == string::npos) {
            cout << "Invalid format. Use A->production1|production2\n";
            return 1;
        }

        string head = input.substr(0, arrowPos);
        string rest = input.substr(arrowPos + 2);
        stringstream ss(rest);
        string prod;
        vector<string> productions;
        while (getline(ss, prod, '|')) {
            productions.push_back(prod);
        }

        grammar.push_back({ head, productions });
    }

    removeLeftRecursion();

    return 0;
}