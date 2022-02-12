#include<iostream>
#include<fstream>
#include<cstdio>
#define MAX_FILE_NAME_SIZE 500
#define ll long long int
using namespace std;



int main()
{
    char fileName[MAX_FILE_NAME_SIZE+1] = "sat1.cnf";
    FILE* fp = fopen("sat1.cnf", "r");
    ll num_clauses, num_vars;
    fscanf(fp, "p cnf %lld %lld", &num_vars, &num_clauses);

    // Now implement function to parse the clauses

    // 1. Do unit propagation: unit clauses should be assigned TRUE value 


    return 0;


}

