#include<iostream>
using namespace std;

const int zones=5;
const int days=7;

void inputpowerusage(int water[zones][days]);
int calculateweeklytotal(int water[zones][days],int zonenumber);
double calculateaverage(int weeklytotal);
bool detectleakage(int water[zones][days],int zone);
void displayFinalResults(int weeklyTotal[], double average[],
                         bool leakageFlag[], bool overuseFlag[],
                         int maxZone);

void inputpowerusage(int water[zones][days])
{
    for(int z=0;z<zones;z++)
    {
        cout<<"Enter data for zone : "<< z+1 <<endl;
        
        for(int d=0;d<days;d++)
        {
            while(true)
            {
                cout<<" Day " << d+1 <<endl;
                cin>> water[z][d];
                
                if( water[z][d] >=0 && water[z][d] <=10000 )
                break;
                else
                cout<< " Enter the value between 0 and 10000" <<endl;
            }
        }
    }
}

int calculateweeklytotal(int water[zones][days],int zone)
{
    int total=0;
    for(int d=0;d<days;d++)
    {
        total+=water[zone][d];
    }
    return total;
}

double calculateaverage(int weeklytotal)
{
    return weeklytotal/7.0;
}

bool detectleakage(int water[zones][days],int zone)
{
    for(int d=0;d < days - 2;d++)
    {
        if (water[zone][d] < water[zone][d+1]  &&
        water[zone][d+1] < water[zone][d+2])
        {
            return true;
        }
    }
    return false;
}

void displayFinalResults(int weeklytotal[], double average[],
                         bool leakageFlag[], bool overuseFlag[],
                         int maxZone)
{
    cout << " Final Report " <<endl;
     
     for(int z=0;z < zones;z++)
     {
         cout<< "\n zone"<< z+1 <<endl;
         cout<< " Total weekly Usage :"<<weeklytotal[z]<<endl;
         cout<< " Average daily Usage :  "<<average[z]<<endl;
                             
     if(leakageFlag[z])
     {
        cout << " Leakage Status      : Possible Leakage Detected\n";
     }
     else
     {
            cout << " Leakage Status      : Normal\n";
     }

    if(overuseFlag[z])
    {
            cout << " Overuse Alert       : YES\n";
    }
    else
    {
            cout << " Overuse Alert       : NO\n";
    }
     }
    

    cout << "Zone with Highest Water Consumption: Zone "
         << maxZone + 1 << endl;

}


int main()
{
    int water[zones][days];
    int weeklyTotal[zones];
    double average[zones];
    bool leakageFlag[zones] = {false};
    bool overuseFlag[zones] = {false};

    int maxZone = 0;
    inputpowerusage(water);

    for (int z = 0; z < zones; z++)
    {
        weeklyTotal[z] = calculateweeklytotal(water, z);
        average[z] = calculateaverage(weeklyTotal[z]);

        leakageFlag[z] = detectleakage(water, z);

        if (average[z] > 8000)
        {
            overuseFlag[z] = true;
        }

        if (weeklyTotal[z] > weeklyTotal[maxZone])
        {    
            maxZone = z;
        }
    }
    displayFinalResults(weeklyTotal, average,
                        leakageFlag, overuseFlag,
                        maxZone);
    
    return 0;
}
