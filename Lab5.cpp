#include <iostream>
using namespace std;

int s=1, n=0, e=5;
int item = 0;

void producer()
{
  s--;    //Put lock so that consumer cant access the buffer
  n++;    //Producer produces 1 item
  e--;    //size of available buffer decreases by 1

  item++;
  cout<<"Item "<<item<<" produces\n\n";
  s++;    //Provide mutex after producer is done
}

void consumer()
{
  s--;    //Put lock so that producer cant access the buffer
  n--;    //consumer comsumes 1 item
  e++;    //size of available buffer increases by 1

  cout<<"Item "<<item<<" is consumed\n\n";
  item--;
  s++;    //Provide mutex after consumer is done
}

int main() 
{
  int choice;
  
  for(int i=1;i>0;i++)
  {
    //cout<<n;
    cout<<"Enter Your Choice:-\n\n1. Produce\n2. Consume\n3.Abort\n\n-->";
    cin>>choice;
    switch(choice)
    {
      case 1:
      if(s==1 && e !=0)
      {
        producer();
      }

      else
      {
        cout<<"Buffer overflow\n\n";
      }
      break;
      

      case 2:
      if((s==1) && (n != 0))
      {
        consumer();
      }

      else
      {
        cout<<"Buffer Underflow\n\n";
      }
      break;

      case 3:
      break;
    }
  }
}