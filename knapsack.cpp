#include <cstring>
#include <iostream>
using namespace std;

int knapsackHelp(int* weight, int* value, int n, int maxWeight, int **output)
{
    int m = n;
    
    if(n == 0 || maxWeight == 0)
    {
        return 0;
    }
    
    if(output[m][maxWeight] != -1)
    {
        return output[m][maxWeight];
    }
    
    int ans;
    
    if(weight[0] > maxWeight)
    {
        ans = knapsackHelp(weight + 1, value + 1, n - 1, maxWeight, output);
    }
    
    else
    {
       int ans1 = knapsackHelp(weight + 1, value + 1, n - 1, maxWeight - weight[0], output);
       int ans2 = knapsackHelp(weight + 1, value + 1, n - 1, maxWeight, output);
        
       ans = max(ans1 + value[0], ans2);
        
    }
    
    output[m][maxWeight] = ans;
    
    return ans;
}

int knapsack(int* weight, int* value, int n, int maxWeight) {
	// Write your code here
    
    int **output;
    
    int m = n;
    
    output = new int* [m + 1];
    
    int i, j;
    
    for(i = 0; i <= m; i++)
    {
        output[i] = new int[maxWeight + 1];
    }
    
    for(i = 0; i <= m; i++)
    {
        for(j = 0; j <= maxWeight; j++)
        {
            output[i][j] = -1;
        }
    }
    
    
    /*for(i = 0; i <= m; i++)
    {
        output[i] = -1;
    }*/
    
    int ans = knapsackHelp(weight, value, n, maxWeight, output);
    
    return ans;
}


int main() {
    int n;
    cin >> n;
    int* wt = new int[n];
    int* val = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    for (int j = 0; j < n; j++) {
        cin >> val[j];
    }

    int w;
    cin >> w;

    cout << knapsack(wt, val, n, w) << "\n";

    delete[] wt;
    delete[] val;
}
