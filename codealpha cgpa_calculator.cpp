#include <iostream>

using namespace std;

void calcGPA();
void calcCGPA();


int main()
{
    
    int choice;
    cout<<"                    GPA & CGPA Calculator              "<<endl;
    cout<<"===================================================================\n"<<endl;
    cout<<"            MENU:"<<endl;
    cout<<"                   1. Calculate GPA "<<endl;
    cout<<"                   2. Calculate CGPA "<<endl;
    
    cout<<"                   4. Exit "<<endl;
    cout<<"==================================================================="<<endl;
    sub:
    cout<<"Enter your choice: ";
    cin>>choice;
    switch(choice)
    {
        case 1:
                calcGPA();
                break;

        case 2:
                calcCGPA();
                break;
    
        case 3:
                exit(EXIT_SUCCESS);
                break;
        default:
            cout<<"wrong choice.Try again!\n"<<endl;
            goto sub;
            break;
    }
}

void calcGPA()
{
    int q;
    
    cout<<"=========== GPA Calculating =============="<<endl;
    cout<<" How many subject's points do you want to calculate : ";
    cin>>q;

    float credit [q];
    float point [q];

    cout<<endl;
    for(int i=0;i<q;i++)
    {
        cout<<"Enter the credit for the subject "<<i+1<<": ";
        cin>>credit[i];
        cout<<endl;
        cout<<"Enter the point of the subject "<<i+1<<": ";
        cin>>point[i];
        cout<<"=========================================\n\n"<<endl;
    }

    float sum=0;
    float tot;
    for(int j=0;j<q;j++)
    {
        tot=credit[j]*point[j];
        sum=sum+tot;
    }

    float totCr=0;
    for(int k=0;k<q;k++)
    {
        totCr=totCr+credit[k];
    }
   cout<<"\n\n\nTotal Points: "<<sum<<" . Total Credits: "<<totCr<<" .Total GPA: "<<sum/totCr<<" ."<<endl;


    sub:
    int inmenu;
    cout<<"\n\n\n1. Calculate Again"<<endl;
    cout<<"2. Go Back to Main Menu"<<endl;
    cout<<"3. Exit This App \n\n"<<endl;
    cout<<"Your choice: "<<endl;
    cin>>inmenu;

    switch(inmenu)
    {
        case 1:
                calcGPA();
                break;
        case 2:
                main();
                break;
        case 3:
                exit(EXIT_SUCCESS);

        default:
              cout<<"\n\nWrong choicet!Please Choose Again!"<<endl;
              goto sub;
    }
}
void calcCGPA()
{
    int l;
    cout<<"=================== CGPA Calculating ====================\n\n"<<endl;
    cout<<"How many semester results do you want input? :";
    cin>>l;
    cout<<"\n\n"<<endl;
    float semrs[l];
    int i;

    for(i=0;i<l;i++)
    {
        cout<<" Enter Semester "<<i+1<<" Result(GPA): ";
        cin>>semrs[i];
        cout<<"\n"<<endl;
    }

    float semtot=0;
    for(int j=0;j<l;j++)
    {
        semtot=semtot+semrs[j];
    }

    cout<<"*** Your CGPA is "<<semtot/l<<" *****"<<endl;


    sub:
    int inmenu;
    cout<<"\n\n\n1. Calculate Again"<<endl;
    cout<<"2. Go Back to Main Menu"<<endl;
    cout<<"3. Exit This App \n\n"<<endl;
    cout<<"Your Input: "<<endl;
    cin>>inmenu;

    switch(inmenu)
    {
        case 1:
                calcCGPA();
                break;
        case 2:
                main();
                break;
        case 3:
                exit(EXIT_SUCCESS);

        default:
              cout<<"\n\nYou have Entered Wrong choice!Please Choose Again!"<<endl;
              goto sub;
    }

}


