#include<iostream>
using namespace std;

double a[12][12];
double target_vector[12],ans_vector[12];
int row_number,column_number;

void print()
{
    for(int i = 1;i <= row_number;i += 1)
    {
        for(int j = 1;j <= column_number;j += 1)
        {
            cout << a[i][j] << " ";
        }
        cout << "| " << target_vector[i] << endl;
    }
}

void swap_row(int row)  //交换两行系数
{
    double tmp;
    for(int i = 1;i <= row_number;i += 1)
    {
        tmp = a[row][i];
        a[row][i] = a[row+1][i];
        a[row+1][i] = tmp;
    }
}

int ltp,pivot;

double ratio;

void elimination(int row,int column) //将column消去
{
    ltp = row;
    while(ltp <= row_number)
    {
        ltp += 1;
        ratio = a[ltp][column] / a[row][column];
        for(int i = 1;i <= column_number; i += 1)
        {
            a[ltp][i] -= a[row][i] * ratio;
        }
        target_vector[ltp] -= target_vector[row] * ratio;
    }
}

void solve()
{
    for(int i = row_number;i >= 1;i -= 1)
    {
        for(int j = column_number;j > i;j -= 1)
        {
            target_vector[i] -= a[i][j] * ans_vector[j];
        }
        ans_vector[i] = target_vector[i] / a[i][i];
    }
}

int main()
{
    cout << "Enter the size of the matrix in m n(split the two number)." << endl;
    
    cin >> row_number >> column_number;
    
    cout << "Please enter the coefficient of the equations like a matrix." << endl;
    
    for(int i = 1;i <= row_number;i += 1)
    {
        for(int j = 1;j <= column_number;j += 1)
        {
            cin >> a[i][j];
        }
    }

    cout << "Please enter the target column vector" << endl;

    for(int i = 1;i <= row_number;i += 1)
    {
        cin >> target_vector[i];
    }

    cout << "Alright.Wait a second for the elimination." << endl;

    for(int i = 1;i <= row_number;i += 1)
    {
        elimination(i,i);
        print();
    }

    solve();
    cout << "The ans should be:" << endl;
    for(int i = 1;i <= row_number;i += 1)
    {
        cout << ans_vector[i] << endl;
    }

    return 0;
}