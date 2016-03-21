#include<iostream>
#include<cmath>
#include<cstdlib>
#include<stdlib.h>
#include<string.h>
#include<set>
using namespace std;

#define  MEM_SIZE 10
//此处内存动态分配逻辑物理页面的大小
int main()
{
    int n=-1;
    int t=4;
    cout<<"-------------缺页率------------"<<endl;
    cout<<"请输入程序需要的页号："<<endl;
   
    cout<<">>";
    int mem[10];
    memset(mem,-1,sizeof(mem));
    bool find=false;
    int t1=0;
    int t2=-1;
    set<int>myset;
    while(cin>>n)
    {
            t2++;
           find=false;
           for(int i=0;i<MEM_SIZE;i++)
           {
                  if(n==mem[i])
                  {
                               
                     cout<<"内存中存在:"<<n<<endl;
                     find =true;            
                   }  
           }
           if(find)
           {
              continue;     
           }
           for(int i=0;i<MEM_SIZE;i++)
           {
               if(mem[i]==-1)
               {
                   mem[i]=n;
                   find=true;           
               }    
           }
           if (find) continue;
           
           myset.insert(n);
           
           
            int aa[MEM_SIZE];
            for(int i=0;i<MEM_SIZE;i++) aa[i]=-1;
            int r=0;
           if((t2-t1)>t)
           {
                        t1=t2;
                        for(set<int>::iterator it=myset.begin();it!=myset.end();it++)
                        {
                                           
                              aa[r]=*it;
                              r++;
                              if(r>=MEM_SIZE) r=0;
                                               
                        }        
                   for(int i=0;i<MEM_SIZE;i++)
                   {     bool findmem=false;
                         for(int j=0;j<MEM_SIZE;j++)
                         {
                              if(mem[i]==aa[j])
                              {
                               findmem=true;
                               break;                                                
                              }
                                  
                         }
                         if(!findmem) mem[i]=-1;
                             
                   }        
                        
                        
            }
           
          cout<<">>";       
    }
    return 0;   
} 

