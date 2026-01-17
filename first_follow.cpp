#include <bits/stdc++.h>
using namespace std;

using Str = string;
using Prod = vector<Str>;
using Prods = vector<Prod>;
const Str eps = "?";
const Str DOLLAR = "$";

unordered_map<Str, Prods> G;
set<Str> nonterminals, terminals;
unordered_map<Str, set<Str>> FIRST, FOLLOW;
map<pair<Str, Str>, Prod> parsingTable; 

void printSet(const set<Str>& s) 
{
    cout << "{ ";
    bool first = true;
    for (auto &x : s) {
        if (!first) cout << ", ";
        cout << x;
        first = false;
    }
    cout << " }";
}

set<Str> firstOfSequence(const Prod &alpha) 
{
    set<Str> result;
    bool allNullable = true;
    for (auto &X : alpha) {
        for (auto &s : FIRST[X]) if (s != eps) result.insert(s);
        if (FIRST[X].count(eps)) continue;
        allNullable = false;
        break;
    }
    if (allNullable) result.insert(eps);
    return result;
}

int main() 
{
    G["E"]  = { {"T", "E'"} };
    G["E'"] = { {"+", "T", "E'"}, {eps} };
    G["T"]  = { {"F", "T'"} };
    G["T'"] = { {"*", "F", "T'"}, {eps} };
    G["F"]  = { {"(", "E", ")"}, {"id"} };

    for (auto &p : G) nonterminals.insert(p.first);
    for (auto &p : G)
        for (auto &rhs : p.second)
            for (auto &sym : rhs)
                if (nonterminals.count(sym) == 0 && sym != eps)
                    terminals.insert(sym);
    terminals.insert(DOLLAR);

    for (auto &t : terminals) FIRST[t].insert(t);
    FIRST[eps].insert(eps);

    bool changed = true;
    while (changed) {
        changed = false;
        for (auto &A : G) {
            for (auto &alpha : A.second) 
            {
                set<Str> firstAlpha = firstOfSequence(alpha);
                size_t before = FIRST[A.first].size();
                FIRST[A.first].insert(firstAlpha.begin(), firstAlpha.end());
                if (FIRST[A.first].size() != before) changed = true;
            }
        }
    }

    FOLLOW["E"].insert(DOLLAR);

    changed = true;
    while (changed) {
        changed = false;
        for (auto &A : G) {
            for (auto &alpha : A.second) 
            {
                for (size_t i = 0; i < alpha.size(); ++i)
                 {
                    Str B = alpha[i];
                    if (nonterminals.count(B) == 0) continue;
                    Prod beta(alpha.begin() + i + 1, alpha.end());
                    set<Str> firstBeta = firstOfSequence(beta);
                    size_t before = FOLLOW[B].size();
                    for (auto &x : firstBeta)
                        if (x != eps) FOLLOW[B].insert(x);
                    if (firstBeta.count(eps) || beta.empty())
                        FOLLOW[B].insert(FOLLOW[A.first].begin(), FOLLOW[A.first].end());
                    if (FOLLOW[B].size() != before) changed = true;
                }
            }
        }
    }

    for (auto &A : G) {
        for (auto &alpha : A.second) 
        {
            set<Str> firstAlpha = firstOfSequence(alpha);
            for (auto &t : firstAlpha) 
            {
                if (t != eps)
                    parsingTable[{A.first, t}] = alpha;
            }
            if (firstAlpha.count(eps)) 
            {
                for (auto &b : FOLLOW[A.first]) 
                {
                    parsingTable[{A.first, b}] = alpha;
                }
            }
        }
    }

    cout << "First sets:\n";
    for (auto &A : nonterminals) 
    {
        cout << "(" << A << ") = ";
        printSet(FIRST[A]);
        cout << "\n";
    }

    cout << "\nFollow sets:\n";
    for (auto &A : nonterminals) 
    {
        cout << "(" << A << ") = ";
        printSet(FOLLOW[A]);
        cout << "\n";
    }

} 