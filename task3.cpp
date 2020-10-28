#include<iostream>
#include<fstream>
#include<string>
#include<regex>
#include<ctype.h>
#include<stdlib.h>
using namespace std;
class aggregate
{
    public:
    void sorting(double arr[][10],int i,int col)
    {
        cout<<"\n\t__________________________Sorting the Sensor values__________________________\t\n";
        for(int j=0;j<col;j++)
        {
            for(int k=0;k<i-1;k++)
            {
                for(int p=0;p<i-k-1;p++)
                {
                if(arr[p][j]>arr[p+1][j])
                {
                swap(arr[p][j],arr[p+1][j]);
                }
                }
            }
        }
    }
    void display(double arr[][10],int i,int col)
    {
        for(int j=0;j<i;j++)
        {
            for(int k=0;k<col;k++)
            {
                cout<<arr[j][k]<<"\t";
            }
        }
    }
};
class sensor{
private:
    enum sen{Left_top,Right_top,Left_bottom,Right_bottom};
    double weight_comp,limit=5.0;
public:
    void left_top_door_compute(double arr[][10],int i,int col){
        sen a=Left_top;
        cout<<"______Left top sensor data______\n";
         for(int j=0;j<i;j++)
        {
            for(int k=0;k<col;k++)
            {
                if(a==k)
            {
            weight_comp=arr[j][k];
            if(weight_comp>=limit)
            {
                cout<<"Left top Door opens for"<<weight_comp<<endl;
            }
            else if(arr[j][k]<limit){
                cout<<"No action ,safe"<<weight_comp<<endl;
            }
        }
            }
    }
    }
    void Right_top_door_compute(double arr[][10],int i,int col){
        sen b=Right_top;
        cout<<"______Right top sensor data______\n";
         for(int j=0;j<i;j++)
        {
            for(int k=0;k<col;k++)
            {
                if(b==k)
            {
            weight_comp=arr[j][k];
            if(weight_comp>=limit)
            {
                cout<<"Right top Door opens for"<<weight_comp<<endl;
            }
            else if(arr[j][k]<limit){
                cout<<"No action ,safe"<<weight_comp<<endl;
            }
        }
            }
    }
    }
    void left_bottom_door_compute(double arr[][10],int i,int col){
        sen c=Left_bottom;
        cout<<"______Left bottom sensor data______\n";
         for(int j=0;j<i;j++)
        {
            for(int k=0;k<col;k++)
            {
                if(c==k)
            {
            weight_comp=arr[j][k];
            if(weight_comp>=limit)
            {
                cout<<"Left bottom Door opens for"<<weight_comp<<endl;
            }
            else if(arr[j][k]<limit){
                cout<<"No action ,safe"<<weight_comp<<endl;
            }
        }
            }
    }
    }
    void Right_bottom_door_compute(double arr[][10],int i,int col){
        sen d=Right_bottom;
        cout<<"______Right bottom sensor data______\n";
         for(int j=0;j<i;j++)
        {
            for(int k=0;k<col;k++)
            {
                if(d==k)
            {
            weight_comp=arr[j][k];
            if(weight_comp>=limit)
            {
                cout<<"Right bottom Door opens for"<<weight_comp<<endl;
            }
            else if(arr[j][k]<limit){
                cout<<"No action ,safe"<<weight_comp<<endl;
            }
            }
            }
    }
    }
    };
/*class sensor{
private:
    double weight_comp,limit=5.0;
public:
    void compute(double arr[][10],int i){
         for(int j=0;j<i;j++)
        {
            weight_comp=arr[j][2];
            if(arr[j][2]>=limit)
            {
                cout<<"Door opens for"<<weight_comp<<endl;
            }
            else if(arr[j][2]<limit){
                cout<<"No action ,safe"<<weight_comp<<endl;
            }
        }
    }
    }; */
int main () {
sensor ob;
aggregate ob1;
  string line;
  //float weight_comp,limit=5.2;
  int i=0,j=0,k=0,len,last=0;
  string num = "";
  double arr[1000][10];
  ifstream infile ("car.csv");

  if(infile.is_open())
  {
    while ( getline(infile,line) )
    {
       k=0,last=0,j=0;
       len=line.length();

        while(k!=len){
                if(line[k]==','||k==len-1){
                        //for converting string into number
                    arr[i][j]=atof(num.append(line,last,k).c_str());
                    num="";
                    j++;
                    if(k!=len-1)
                    last=k+1;
                }
                k++;
        }
        i++;
    }
    //close the file
    infile.close();
  }
  else cout << "Unable to open file";
  cout<<"Matrix of CSV file below \n";

  int col=0;
    for(int x=0;x<len;x++){
       if(line[x]==',')
       col++;
       }
    // i= number of rows
    // col = number of columns
   for(int l=0;l<i;l++){
        for(int m=0;m<col;m++){
        cout<<arr[l][m]<<"\t";
        }
   cout<<"\n";
     }
  ob.left_top_door_compute(arr,i,col);
  ob.Right_top_door_compute(arr,i,col);
  ob.left_bottom_door_compute(arr,i,col);
  ob.Right_bottom_door_compute(arr,i,col);
  ob1.sorting(arr,i,col);
  ob1.display(arr,i,col);
  return 0;
}

