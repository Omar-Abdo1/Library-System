#include <iostream>
#include<bits/stdc++.h>
using namespace std;
const int Max_Borrow=3;
vector<vector<int>>v;
struct Book
{
    string name;
    int id,qu,borrow;
    void set()
    {
        borrow=0;
    }

};
struct User
{
    string name;
    int id,aleh;
    vector<int>v;
    void set()
    {
        aleh=0;
    }
};
Book arr[25];
User arr1[25];
int len=0,len1=0;
bool com1(Book a, Book b)
{
    return a.id<b.id;
}

bool com2(Book a, Book b)
{
    return a.name<b.name;
}


void Add_Book()
{
    cout<<"Enter Name Of The Book : ";
    string s;
    cin>>s;
    bool ok=1;
    for(int i=0; i<len; ++i)
    {
        if(arr[i].name==s)
        {
            ok=0;
            break;
        }
    }
    if(ok)
    {
        cout<<"Enter Id, Quantity : ";
        cin>>arr[len].id>>arr[len].qu;
        arr[len].name=s;
        len++;
    }
    else
    {
        cout<<"Sorry We Can Not Add This Book Because There Are Already Book Named "<<s<<"\n";
    }

}
void Search_Books()
{
    cout<<"Enter Name For Searched Book : ";
    string s;
    cin>>s;
    int c=0;
    for(int i=0; i<len; ++i)
    {
        if(arr[i].name.find(s)!=-1)
        {
            c++;
        }
    }
    if(!c)
    {
        cout<<"There Are No Book That Can Found By "<<s<<"\n";
        return;
    }
    cout<<"There Are "<<c<<" Books That We Have Founded : \n";
    for(int i=0; i<len; ++i)
    {
        if(arr[i].name.find(s)!=-1)
        {
            cout<<arr[i].name<<"\n";
        }
    }

}

void Print_By_Id()
{
    if(!len)
    {
        cout<<"There Are No Book Yet !\n";
        return ;
    }
    cout<<"Books Sorted By Id : \n";
    sort(arr,arr+len,com1);
    for(int i=0; i<len; ++i)
    {
        cout<<"name = "<<arr[i].name<<" "<<" Id = "<<arr[i].id<<" Quantity = "<<arr[i].qu<<"  Total Borrow = "<<arr[i].borrow<<"\n";
    }
}

void Print_By_Name()
{
    if(!len)
    {
        cout<<"There Are No Book Yet !\n";
        return ;
    }
    cout<<"Books Sorted By Name : \n";
    sort(arr,arr+len,com2);
    for(int i=0; i<len; ++i)
    {
        cout<<"name = "<<arr[i].name<<" "<<" Id = "<<arr[i].id<<" Quantity = "<<arr[i].qu<<"  Total Borrow = "<<arr[i].borrow<<"\n";
    }
}

void Who_Borrow_Book_By_Name()
{
    cout<<"Enter A Name For A Book : ";
    string s;
    cin>>s;
    int ind=0;
    bool ok=0;
    for(int i=0; i<len; ++i)
    {
        if(arr[i].name==s)
        {
            ind=i;
            ok=1;
            break;
        }
    }
    if(!ok)
    {
        cout<<"There Are No Book That Have Name : "<<s<<"\n";
        return ;
    }
    int c=0;

    int id=arr[ind].id;

    for(int i=0; i<len1; ++i)
    {

        for(int j=0; j<arr1[i].v.size(); ++j)
        {
            if(arr1[i].v[j]==id)
            {
                cout<<arr1[i].name<<"\n";
                c++;
                break;
            }
        }

    }
    if(!c){
        cout<<"There Are No Users Borrowed Books Yet !\n";
    }

}

void ADD_User()
{
    cout<<"Enter Name Of The User : ";
    string s;
    cin>>s;
    bool ok=1;
    for(int i=0; i<len1; ++i)
    {
        if(arr1[i].name==s)
        {
            ok=0;
            break;
        }
    }
    if(ok)
    {
        cout<<"Enter Id : ";
        cin>>arr1[len1].id;
        arr1[len1].name=s;
        len1++;
    }
    else
    {
        cout<<"User Name ALready Used Try New One :) "<<"\n";
    }

}

void User_Borrow_Book()
{

    cout<<"Enter Name Of User And The Name Of The Book : ";
    string s,t;
    cin>>s>>t;
    bool ok1=0,ok2=0;
    int ind1=0,ind2=0;
    for(int i=0; i<len1; ++i)
    {
        if(arr1[i].name==s)
        {
            ok1=1;
            ind1=i;
            break;
        }
    }

    for(int i=0; i<len; ++i)
    {
        if(arr[i].name==t)
        {
            ok2=1;
            ind2=i;
            break;
        }
    }

    if(!ok1)
    {
        cout<<"There Are No Person Called "<<s<<"\n";
        return ;
    }

    if(!ok2)
    {
        cout<<"There Are No Book Named "<<t<<"\n";
        return ;
    }

    for(int i=0; i<arr1[ind1].v.size(); ++i)
    {
        if(arr1[ind1].v[i]==arr[ind2].id)
        {
            cout<<"This Person Has Already Borrow This Book\n";
            return ;
        }
    }

    if(arr1[ind1].aleh+1<=Max_Borrow)
    {

        if(arr[ind2].qu>0)
        {

            arr1[ind1].v.push_back(arr[ind2].id);
            arr[ind2].borrow++;
            arr[ind2].qu--;
            arr1[ind1].aleh++;
        }
        else
        {
            cout<<"We Do Not Have Much Quantity For This Book Sorry :)\n";
            return ;
        }



    }
    else
    {
        cout<<"This Person Has Exceed The Maximum Number Of Books Please Return It : )\n";
        return ;
    }

}

void User_Return_Book()
{

    cout<<"Enter Name Of User And The Name Of The Book : ";
    string s,t;
    cin>>s>>t;
    bool ok1=0,ok2=0;
    int ind1=0,ind2=0;
    for(int i=0; i<len1; ++i)
    {
        if(arr1[i].name==s)
        {
            ok1=1;
            ind1=i;
            break;
        }
    }

    for(int i=0; i<len; ++i)
    {
        if(arr[i].name==t)
        {
            ok2=1;
            ind2=i;
            break;
        }
    }

    if(!ok1)
    {
        cout<<"There Are No Person Called "<<s<<"\n";
        return ;
    }

    if(!ok2)
    {
        cout<<"There Are No Book Named "<<t<<"\n";
        return ;
    }

    bool ok=0;
    int idx=0;
    for(int i=0; i<arr1[ind1].v.size(); ++i)
    {
        if(arr1[ind1].v[i]==arr[ind2].id)
        {
            idx=i;
            ok=1;
            break;
        }
    }
    if(!ok)
    {
        cout<<"This Person Has Not Borrow This Book\n";
        return ;
    }
    arr[ind2].borrow--;
    arr[ind2].qu++;
    arr1[ind1].v[idx]=-1;
    arr1[ind1].aleh--;
}

void Print_Users()
{

    if(!len1)
    {
        cout<<"There Are No Users Yet !\n";
        return ;
    }
    for(int i=0; i<len1; ++i)
    {

        cout<<"User = "<<arr1[i].name<<"  id= "<<arr1[i].id<<", ";

        if(arr1[i].aleh==0)
        {
            cout<<arr1[i].name<<" Has Not Borrowed Book Yet ! \n";
        }
        else
        {
            cout<<arr1[i].name<<" Has Books With Id : \n";
            for(int j=0; j<arr1[i].v.size(); ++j)
            {
                if(arr1[i].v[j]!=-1)
                {
                    cout<<arr1[i].v[j]<<" ";
                }
            }
            cout<<"\n";
        }

    }




}

void Library_System()
{

    while(1)
    {
        cout<<"Library Menu :\n";
        cout<<"1) Add Book \n";
        cout<<"2) Search Books  \n";
        cout<<"3) Print Who Borrow Book By Name  \n";
        cout<<"4) Print Library By Id \n";
        cout<<"5) Print Library By Name \n";
        cout<<"6) Add User \n";
        cout<<"7) User_Borrow_Book \n";
        cout<<"8) User_Return_Book \n";
        cout<<"9) Print Users \n";
        cout<<"10) Exit \n\n";
        cout<<"Enter Your Menu Choice [1,10] ->> : ";

        int choice;
        cin>>choice;
        if(choice==1)
        {
            Add_Book();
        }
        else if(choice==2)
        {
            Search_Books();
        }
        else if(choice==3)
        {
            Who_Borrow_Book_By_Name();
        }
        else if(choice==4)
        {
            Print_By_Id();
        }
        else if(choice==5)
        {
            Print_By_Name();
        }
        else if(choice==6)
        {
            ADD_User();
        }
        else if(choice==7)
        {
            User_Borrow_Book();
        }
        else if(choice==8)
        {
            User_Return_Book();
        }
        else if(choice==9)
        {
            Print_Users();
        }
        else
        {
            break;
        }


    }


}





int main()
{
    Library_System();
    return 0;
}

//1   math4 101 3
//1   math2 102 5
//1   math1 103 4
//1   math3 104 2
//1   prog11 201 5
//1   prog2 201 3
//4
//5
//6 mostafa     30301
//6 ali		  50501
//6 noha        70701
//6 ashraf      90901
//7 mostafa math1
//7 mostafa math2
//7 mostafa math3
//7 ali math1
//7 ali math2
//7 noha math1
//7 noha math3
//7 noha prog2
//4
//9
//2 ma
//2 pro
//2 machine
//3 math1
//3 math2
//3 machine
//4
//9
//8 mostafa math1
//4
//9
//10
