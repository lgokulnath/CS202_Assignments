#include<bits/stdc++.h>
#define MAX_FILE_NAME_SIZE 500
#define ll long long int
using namespace std;

// Possible improvements
// 1. sort the clauses

 // Now implement function to parse the clauses

    // 1. Do unit propagation: unit clauses should be assigned TRUE value should be done at every step
    //    if any clause has only one variable
    // 2. Reduction of variables
    // 3. PURE LITERALS: if a literal occurs in only one polarity, then assign it to true and do the above 1 & 2

    /*
    dpll(F, literal) {
        remove clauses containing literal
        if (F contains no clauses) return True
        shorten clauses containing ~literal
        if(F contains empty clause) 
            return False;
        choose V in F
        if(dpll(F, ~V)) return true;
        return dpll(F,V)
    }

    */
// return dpll(formulas, 1) || dpll(formulas, -1)

void display_formulas(vector<vector<ll> > formulas, ll num_clauses)
{
    
    for(ll i = 0; i < num_clauses; i++) {
        for(ll j = 0; j < formulas[i].size(); j++) {
            cout << formulas[i][j] << " ";
        }
        cout << "\n";
    }
    return;
}


void remove_clauses(vector<vector<ll> >& formulas, ll literal, ll num_clauses)
{
    ll i, j;
    
    for(i = 0; i < formulas.size(); i++) {
        if(formulas[i].size() > 0 && find(formulas[i].begin(), formulas[i].end(), literal) != formulas[i].end()) {
            formulas.erase(formulas.begin() + i);
        }
    }

    display_formulas(formulas, num_clauses);
}

bool dpll(vector<vector<ll> > formulas, ll literal, ll num_clauses)
{
    remove_clauses(formulas, literal, num_clauses);
}




int main()
{
    char fileName[MAX_FILE_NAME_SIZE+1] = "sat1.cnf";
    FILE* fp = fopen("sat1.cnf", "r");
    ll num_clauses, num_vars;
    fscanf(fp, "p cnf %lld %lld", &num_vars, &num_clauses);
    ll i;
    vector<vector<ll> > formulas(num_clauses);
    for(i = 0; i < num_clauses; i++) {
        ll temp;
        fscanf(fp, "%lld", &temp);
        while(temp != 0) {
            formulas[i].push_back(temp);
            fscanf(fp, "%lld", &temp);
        }
    }
    display_formulas(formulas, num_clauses);
    dpll(formulas, 1, num_clauses);
   
    return 0;


}

