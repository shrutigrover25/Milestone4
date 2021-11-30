// we will use the approach of greedy algorithm.
//calculate the ratio value/weight for each item and sort the item on basis of this ratio. Then take the item with the highest ratio and add them until we can’t add the next item as a whole
// and at the end add the next item as much as we can.
// time complexity - O(n);

#include <bits/stdc++.h>
  
using namespace std;
  
/
struct Item {
    int value, weight;
  
    
    Item(int value, int weight)
    {
       this->value=value;
       this->weight=weight;
    }
};
  

bool cmp(struct Item a, struct Item b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}
  

double fractionalKnapsack(int W, struct Item arr[], int n)
{
    
    sort(arr, arr + n, cmp);
  
    
    for (int i = 0; i < n; i++)
    {
        cout << arr[i].value << "  " << arr[i].weight << " :
    "
             << ((double)arr[i].value / arr[i].weight) <<
    endl;
    }
    */
  
    int curWeight = 0; 
    double finalvalue = 0.0;
  
    
    for (int i = 0; i < n; i++) {
        
        if (curWeight + arr[i].weight <= W) {
            curWeight += arr[i].weight;
            finalvalue += arr[i].value;
        }
  
       
        else {
            int remain = W - curWeight;
            finalvalue += arr[i].value
                          * ((double)remain
                             / (double)arr[i].weight);
            break;
        }
    }
  
    return finalvalue;
}
  
int main()
{
    int W = 50;
    Item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
  
    int n = sizeof(arr) / sizeof(arr[0]);
  
    
    cout << "Maximum value we can obtain = "
         << fractionalKnapsack(W, arr, n);
    return 0;
}