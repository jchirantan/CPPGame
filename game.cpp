#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#include <windows.h>
#include <math.h>
using namespace std;
class animal
{
        public:
		int id;
		char name[30];
		float prob;
		void search()
		{
		    int d;
		    cout<<"Enter the id of the record you want\n";
		    cin>>d;
		    fstream file;
		    animal d1;
		    file.open("TROPICAL1.txt",ios::in|ios::binary);
		    while(!file.eof())
		    {
		        file.read((char*)&d1,sizeof(animal));
		        if(d1.id==d)
		        {
		            cout<<"The id of the animal is: "<<d1.id<<endl;
		            cout<<"The name of the animal is: "<<d1.name<<endl;
		            cout<<"The prob of taming an animal is: "<<d1.prob<<endl;
		        }
		    }
		        file.close();
		}
		void accept()
		{
		    cout<<"Enter the id of the animal: \n";
		    cin>> id;
		    cout<<"Enter the name of the animal: \n";
		    cin>> name;
		    cout<<"Enter the prob of taming an animal: \n";
		    cin>> prob;
		}
		void create()
		{
		    animal a1;
		    fstream file;
		    a1.accept();
		    file.open("TROPICAL1.txt",ios::app|ios::binary);
		    file.write((char*)&a1,sizeof(animal));
		    cout<<"The animal has been added to your file.\n";
		    file.close();
		}
		void displayall()
		{
		    fstream file;
		    animal b1;
		    file.open("abc.txt",ios::in|ios::binary);
		    cout<<"ID\t\t\tNAME\t\t\tPROBABILITY"<<endl;
		    while(file.read((char*)&b1,sizeof(animal)))
		    {
		        cout<<b1.id<<"\t\t\t"<<b1.name<<"\t\t\t"<<b1.prob<<endl;
		    }
		    file.close();
		}
};
class escape
{
    public:
        int health;
        char location[15];
        char vehicle[15];
        double x;
        escape()
        {
            x=((double) rand() / (RAND_MAX));
            x=((double) rand() / (RAND_MAX));
            health=100;
            if(x>=0&&x<0.15)
            {  
                strcpy(location, "ARCTIC");
                strcpy(vehicle, "SNOW SLEDGE");
	    }
            else if (x>=0.85&&x<=1)
            {
                strcpy(location, "DESERT");
                strcpy(vehicle, "JEEP");
            }
            else if(x>=0.15&&x<0.5)
            {
                strcpy(location, "OCEAN");
                strcpy(vehicle, "RAFT");
            }
            else 
            {
                strcpy(location, "TROPICAL");
                strcpy(vehicle, "ON FOOT");
            }
        }
        void sleep(unsigned milliseconds)
        {
	    Sleep(milliseconds);
	}
        void display()
        {
            cout<<"\t\t\t\tWELCOME TO THE WILDLIFE ADVENTURE GAME!\n\n";
            sleep(3000);
            cout<<"\tAS WE HAVE JUST FOCUSED ON THE CODE AND LOGIC WE REGRET TO INFORM YOU THAT WE DON'T SUPPORT VISUAL GRAPHICS RIGHT AT THIS MOMENT\n\n";
            sleep(6000);
            cout<<"\t\t\tTHE ONLY ACCEPTABLE INPUTS FROM YOU, THE USER, ARE 'YES' AND 'NO' \n\n";
            sleep(3000);
            cout<<"\t\t\t\tSO LET'S BEGIN!\n\n\n\n";
            sleep(1000);
            cout<<"INSTRUCTIONS:\n";
            sleep(1000);
            cout<<"1. YOU START WITH A HEALTH INDEX OF 100, AND A REGION WHERE YOU ARE ALL ALONE\n";
            sleep(1000);
            cout<<"2. YOUR JOB IS TO SURVIVE!\n";
            sleep(1000);
            cout<<"3. EVERY MOVE YOU MAKE YOUR HEALTH INDEX FALLS BY 10.\n";
            sleep(1000);
            cout<<"4. AND AT EVERY MOVE YOU ENCOUNTER AN ANIMAL!\n";
            sleep(1000);
            cout<<"5. YOU CAN EITHER TRY TO TAME THAT ANIMAL OR LET THAT ANIMAL GO\n";
            sleep(1000);
            cout<<"6. IF YOUT TAME THAT ANIMAL, THE ANIMAL FOLLOWS YOU AROUND AND YOU CAN TRY TO KILL IT FOR FOOD IN THE NEXT MOVE\n";
            sleep(1000);
            cout<<"7. EVERY TIME YOU TRY TO TAME AN ANIMAL OR COMBAT WITH AN ANIMAL YOUR HEALTH INDEX FALLS BY 10..\n\tBUT IF YOU ARE SUCCESSFUL IN TRYING TO KILL THE ANIMAL THEN YOUR HEALTH INDEX WILL INCREASE BY 30\n";
            sleep(1000);
            cout<<"\n\n\nDo you want to start the game?\n";
            cout<<"PLAYER INPUT: ";
            sleep(1000);
            char y[5];
            cin>>y;
            if(!strcmp(y,"YES")==0)
            {
		exit(0);
	    }
        }
};
class arctic: public escape, public animal
{
        public:
        arctic()
        {
            cout<<"\n\nYOU ARE CURRENTLY STRANDED IN ANTARCTICA\n";
            sleep(1000);
            cout<<"YOU HAVE A SNOW SLEDGE AT YOUR DISPOSAL\n";
            sleep(1000);
            cout<<"YOUR CURRENT HEALTH IS :"<<health<<endl;
            sleep(1000);
        }
        void move()
        {
            sleep(1000);
            cout<<"\n\n\nDo you want to make a move?\n";
            sleep(1000);
            cout<<"PLAYER INPUT: ";
            char o[5];
            cin>>o;
            if(!strcmp(o,"YES")==0)
            {
		exit(0);
	    }
            sleep(1000);
            health-=10;
            cout<<"YOUR CURRENT HEALTH IS :"<<health<<endl;
            sleep(1000);
        }
        void getanimal()
        { 
            srand(time(0));
            x=((double) rand() / (RAND_MAX));
            x=((double) rand() / (RAND_MAX));
            x=((double) rand() / (RAND_MAX));
            x=((double) rand() / (RAND_MAX));
            int i;
            i=ceil(7*x);
            fstream file;
            animal d1;
            file.open("ARCTIC1.txt",ios::in|ios::binary);
            while(!file.eof())
            {
                file.read((char*)&d1,sizeof(animal));
                if(d1.id==i)
                {
                    sleep(1000);
                    cout<<"\n\nThe animal you just encountered: "<<d1.name<<endl;
                    sleep(1000);
                    cout<<"The probablity of taming the animal is: "<<((d1.prob)*100)<<"%"<<endl;
                }
            }
            file.close();
            sleep(1000);
            cout<<"\n\n\nDo you wish to tame the animal?\n";
            sleep(1000);
            cout<<"PLAYER INPUT: ";
            char y[5];
            cin>>y;
            if(strcmp(y,"YES")==0)
            {
                float g;
                srand(time(0));
                x=((double) rand() / (RAND_MAX));
                x=((double) rand() / (RAND_MAX));
                x=((double) rand() / (RAND_MAX));
                x=((double) rand() / (RAND_MAX));
                g=x*100;
                if(g>40)
                {
                    sleep(1000);
                    cout<<"The ANIMAL was successfully TAMED!"<<endl;
                    sleep(1000);
                    health-=10;
                    cout<<"YOUR CURRENT HEALTH IS :"<<health<<endl<<endl;
                    sleep(1000);
                    cout<<"\n\n\nDo you wish to try and kill your tamed animal for food?\n";
                    cout<<"JUST REMEMBER, YOU NEED FOOD TO SURVIVE, AND KILLING YOUR TAMED ANIMAL IS THE ONLY WAY YOU GET FOOD!\n";
                    cout<<"PLAYER INPUT: ";
                    char p[5];
                    cin>>p;
                    if(strcmp(p,"YES")==0)
                    {
                        float q,t;
                        srand(time(0));
                        x=((double) rand() / (RAND_MAX));
                        x=((double) rand() / (RAND_MAX));
                        x=((double) rand() / (RAND_MAX));
                        x=((double) rand() / (RAND_MAX));
                        t=(x*100);
                        sleep(1000);
                        cout<<"\nThe probability of winning the combat against your animal is: "<<t<<"%"<<endl<<endl;
                        sleep(1000);
                        cout<<"\nARE YOU SURE YOU WANT TO PROCEED KEEPING THE PROBABLILITY IN MIND?\n\n ALSO REMEMBER THAT IF YOU WIN THE COMBAT YOUR HEALTH INCREASES BY 30\n\tAND IF YOU ARE DEFEATED, \n\tYOUR HEALTH REDUCES BY 20..\n\tSO TREAD CAREFULLY!!\n";
                        sleep(1000);
                        cout<<"PLAYER INPUT: ";
                        srand(time(0));
                        x=((double) rand() / (RAND_MAX));
                        x=((double) rand() / (RAND_MAX));
                        x=((double) rand() / (RAND_MAX));
                        x=((double) rand() / (RAND_MAX));
                        q=(x*100);
                        char y[5];
                        cin>>y;
                        if(strcmp(y,"YES")==0)
                        {
                            if(q>50)
                            {
                                sleep(1000);
                                cout<<"The combat was successful AND YOU GOT A LOT OF FOOD!"<<endl;
                                health+=30;
                                sleep(1000);
                                cout<<"YOUR CURRENT HEALTH IS :"<<health<<endl;
                            }
                            else
                            {
                                sleep(1000);
                                cout<<"THE COMBAT WAS NOT SUCCESSFUL!..BETTER LUCK NEXT TIME"<<endl;
                                health-=20;
                                sleep(1000);
                                cout<<"YOUR CURRENT HEALTH IS :"<<health<<endl;
                            }
                        }
                    }
                }
                else
                {
                    sleep(1000);
                    cout<<"The TAMING OF THE ANIMAL was NOT successful!"<<endl;
                    sleep(1000);
                    health-=10;
                    cout<<"YOUR CURRENT HEALTH IS :"<<health<<endl;
                }
            }
        }
};
class desert: public escape, public animal
{
    public:
        desert()
        {
            cout<<"\n\nYOU ARE CURRENTLY STRANDED IN THE SAHARA DESERT\n";
            sleep(1000);
            cout<<"YOU HAVE A JEEP AT YOUR DISPOSAL\n";
            sleep(1000);
            cout<<"YOUR CURRENT HEALTH IS :"<<health<<endl;
            sleep(1000);
        }
        void move()
        {
            sleep(1000);
            cout<<"\n\n\nDo you want to make a move?\n";
            sleep(1000);
            cout<<"PLAYER INPUT: ";
            char o[5];
            cin>>o;
            if(!strcmp(o,"YES")==0)
            {
                exit(0);
            }
            sleep(1000);
            health-=10;
            cout<<"YOUR CURRENT HEALTH IS :"<<health<<endl;
            sleep(1000);
        }
        void getanimal()
        { 
            srand(time(0));
            x=((double) rand() / (RAND_MAX));
            x=((double) rand() / (RAND_MAX));
            x=((double) rand() / (RAND_MAX));
            x=((double) rand() / (RAND_MAX));
            int i;
            i=7+(ceil(10*x));
            fstream file;
            animal d1;
            file.open("DESERT1.txt",ios::in|ios::binary);
            while(!file.eof())
            {
                file.read((char*)&d1,sizeof(animal));
                if(d1.id==i)
                {
                    sleep(1000);
                    cout<<"\n\nThe animal you just encountered: "<<d1.name<<endl;
                    sleep(1000);
                    cout<<"The probablity of taming the animal is: "<<((d1.prob)*100)<<"%"<<endl;
                }
            }
            file.close();
            sleep(1000);
            cout<<"\n\n\nDo you wish to tame the animal?\n";
            sleep(1000);
            cout<<"PLAYER INPUT: ";
            char y[5];
            cin>>y;
            if(strcmp(y,"YES")==0)
            {
                float g;
                srand(time(0));
                x=((double) rand() / (RAND_MAX));
                x=((double) rand() / (RAND_MAX));
                x=((double) rand() / (RAND_MAX));
                x=((double) rand() / (RAND_MAX));
                g=x*100;
                if(g>40)
                {
                    sleep(1000);
                    cout<<"The ANIMAL was successful TAMED!"<<endl;
                    sleep(1000);
                    health-=10;
                    cout<<"YOUR CURRENT HEALTH IS :"<<health<<endl<<endl;
                    sleep(1000);
                    cout<<"\n\n\nDo you wish to try and kill your tamed animal for food?\n";
                    cout<<"JUST REMEMBER, YOU NEED FOOD TO SURVIVE, AND KILLING YOUR TAMED ANIMAL IS THE ONLY WAY YOU GET FOOD!\n";
                    cout<<"PLAYER INPUT: ";
                    char p[5];
                    cin>>p;
                    if(strcmp(p,"YES")==0)
                    {
                        float q,t;
                        srand(time(0));
                        x=((double) rand() / (RAND_MAX));
                        x=((double) rand() / (RAND_MAX));
                        x=((double) rand() / (RAND_MAX));
                        x=((double) rand() / (RAND_MAX));
                        t=(x*100);
                        sleep(1000);
                        cout<<"\nThe probability of winning the combat against your animal is: "<<t<<"%"<<endl<<endl;
                        sleep(1000);
                        cout<<"\nARE YOU SURE YOU WANT TO PROCEED KEEPING THE PROBABLILITY IN MIND?\n\n ALSO REMEMBER THAT IF YOU WIN THE COMBAT YOUR HEALTH INCREASES BY 30\n\tAND IF YOU ARE DEFEATED, \n\tYOUR HEALTH REDUCES BY 20..\n\tSO TREAD CAREFULLY!!\n";
                        sleep(1000);
                        cout<<"PLAYER INPUT: ";
                        srand(time(0));
                        x=((double) rand() / (RAND_MAX));
                        x=((double) rand() / (RAND_MAX));
                        x=((double) rand() / (RAND_MAX));
                        x=((double) rand() / (RAND_MAX));
                        q=(x*100);
                        char y[5];
                        cin>>y;
                        if(strcmp(y,"YES")==0)
                        {
                            if(q>50)
                            {
                                sleep(1000);
                                cout<<"The combat was successful AND YOU GOT A LOT OF FOOD!"<<endl;
                                health+=30;
                                sleep(1000);
                                cout<<"YOUR CURRENT HEALTH IS :"<<health<<endl;
                            }
                            else
                            {
                                sleep(1000);
                                cout<<"THE COMBAT WAS NOT SUCCESSFUL!..BETTER LUCK NEXT TIME"<<endl;
                                health-=20;
                                sleep(1000);
                                cout<<"YOUR CURRENT HEALTH IS :"<<health<<endl;
                            }
                        }
                    }
                }
                else
                {
                    sleep(1000);
                    cout<<"The TAMING OF THE ANIMAL was NOT successful!"<<endl;
                    sleep(1000);
                    health-=10;
                    cout<<"YOUR CURRENT HEALTH IS :"<<health<<endl;
                }
            }
        }
};
class ocean: public escape, public animal
{
    public:
        ocean()
        {
            cout<<"\n\nYOU ARE CURRENTLY STRANDED IN THE PACIFIC OCEAN\n";
            sleep(1000);
            cout<<"YOU HAVE A RAFT AT YOUR DISPOSAL\n";
            sleep(1000);
            cout<<"YOUR CURRENT HEALTH IS :"<<health<<endl;
            sleep(1000);
        }
        void move()
        {
            sleep(1000);
            cout<<"\n\n\nDo you want to make a move?\n";
            sleep(1000);
            cout<<"PLAYER INPUT: ";
            char o[5];
            cin>>o;
            if(!strcmp(o,"YES")==0)
            {
                exit(0);
            }
            sleep(1000);
            health-=10;
            cout<<"YOUR CURRENT HEALTH IS :"<<health<<endl;
            sleep(1000);
        }
        void getanimal()
        {
            srand(time(0));
            x=((double) rand() / (RAND_MAX));
            x=((double) rand() / (RAND_MAX));
            x=((double) rand() / (RAND_MAX));
            x=((double) rand() / (RAND_MAX));
            int i;
            i=17+(ceil(12*x));
            fstream file;
            animal d1;
            file.open("OCEAN1.txt",ios::in|ios::binary);
            while(!file.eof())
            {
                file.read((char*)&d1,sizeof(animal));
                if(d1.id==i)
                {
                    sleep(1000);
                    cout<<"\n\nThe animal you just encountered: "<<d1.name<<endl;
                    sleep(1000);
                    cout<<"The probablity of taming the animal is: "<<((d1.prob)*100)<<"%"<<endl;
                }
            }
            file.close();
            sleep(1000);
            cout<<"\n\n\nDo you wish to tame the animal?\n";
            sleep(1000);
            cout<<"PLAYER INPUT: ";
            char y[5];
            cin>>y;
            if(strcmp(y,"YES")==0)
            {
                float g;
                srand(time(0));
                x=((double) rand() / (RAND_MAX));
                x=((double) rand() / (RAND_MAX));
                x=((double) rand() / (RAND_MAX));
                x=((double) rand() / (RAND_MAX));
                g=x*100;
                if(g>40)
                {
                    sleep(1000);
                    cout<<"The ANIMAL was successful TAMED!"<<endl;
                    sleep(1000);
                    health-=10;
                    cout<<"YOUR CURRENT HEALTH IS :"<<health<<endl<<endl;
                    sleep(1000);
                    cout<<"\n\n\nDo you wish to try and kill your tamed animal for food?\n";
                    cout<<"JUST REMEMBER, YOU NEED FOOD TO SURVIVE, AND KILLING YOUR TAMED ANIMAL IS THE ONLY WAY YOU GET FOOD!\n";
                    cout<<"PLAYER INPUT: ";
                    char p[5];
                    cin>>p;
                    if(strcmp(p,"YES")==0)
                    {
                        float q,t;
                        srand(time(0));
                        x=((double) rand() / (RAND_MAX));
                        x=((double) rand() / (RAND_MAX));
                        x=((double) rand() / (RAND_MAX));
                        x=((double) rand() / (RAND_MAX));
                        t=(x*100);
                        sleep(1000);
                        cout<<"\nThe probability of winning the combat against your animal is: "<<t<<"%"<<endl<<endl;
                        sleep(1000);
                        cout<<"\nARE YOU SURE YOU WANT TO PROCEED KEEPING THE PROBABLILITY IN MIND?\n\n ALSO REMEMBER THAT IF YOU WIN THE COMBAT YOUR HEALTH INCREASES BY 30\n\tAND IF YOU ARE DEFEATED, \n\tYOUR HEALTH REDUCES BY 20..\n\tSO TREAD CAREFULLY!!\n";
                        sleep(1000);
                        cout<<"PLAYER INPUT: ";
                        srand(time(0));
                        x=((double) rand() / (RAND_MAX));
                        x=((double) rand() / (RAND_MAX));
                        x=((double) rand() / (RAND_MAX));
                        x=((double) rand() / (RAND_MAX));
                        q=(x*100);
                        char y[5];
                        cin>>y;
                        if(strcmp(y,"YES")==0)
                        {
                            if(q>50)
                            {
                                sleep(1000);
                                cout<<"The combat was successful AND YOU GOT A LOT OF FOOD!"<<endl;
                                health+=30;
                                sleep(1000);
                                cout<<"YOUR CURRENT HEALTH IS :"<<health<<endl;
                            }
                            else
                            {
                                sleep(1000);
                                cout<<"THE COMBAT WAS NOT SUCCESSFUL!..BETTER LUCK NEXT TIME"<<endl;
                                health-=20;
                                sleep(1000);
                                cout<<"YOUR CURRENT HEALTH IS :"<<health<<endl;
                            }
                        }
                    }
                }
                else
                {
                    sleep(1000);
                    cout<<"The TAMING OF THE ANIMAL was NOT successful!"<<endl;
                    sleep(1000);
                    health-=10;
                    cout<<"YOUR CURRENT HEALTH IS :"<<health<<endl;
                }
            }
        }
};
class tropical: public escape, public animal
{
    public:
        tropical()
        {
            cout<<"\n\nYOU ARE CURRENTLY STRANDED IN THE AMAZON RAINFOREST\n";
            sleep(1000);
            cout<<"YOU HAVE A KNIFE AT YOUR DISPOSAL\n";
            sleep(1000);
            cout<<"YOUR CURRENT HEALTH IS :"<<health<<endl;
            sleep(1000);
        }
        void move()
        {
            sleep(1000);
            cout<<"\n\n\nDo you want to make a move?\n";
            sleep(1000);
            cout<<"PLAYER INPUT: ";
            char o[5];
            cin>>o;
            if(!strcmp(o,"YES")==0)
            {
                exit(0);
            }
            sleep(1000);
            health-=10;
            cout<<"YOUR CURRENT HEALTH IS :"<<health<<endl;
            sleep(1000);
        }
        void getanimal()
        { 
            srand(time(0));
            x=((double) rand() / (RAND_MAX));
            x=((double) rand() / (RAND_MAX));
            x=((double) rand() / (RAND_MAX));
            x=((double) rand() / (RAND_MAX));
            int i;
            i=29+(ceil(17*x));
            fstream file;
            animal d1;
            file.open("TROPICAL1.txt",ios::in|ios::binary);
            while(!file.eof())
            {
                file.read((char*)&d1,sizeof(animal));
                if(d1.id==i)
                {
                    sleep(1000);
                    cout<<"\n\nThe animal you just encountered: "<<d1.name<<endl;
                    sleep(1000);
                    cout<<"The probablity of taming the animal is: "<<((d1.prob)*100)<<"%"<<endl;
                }
            }
            file.close();
            sleep(1000);
            cout<<"\n\n\nDo you wish to tame the animal?\n";
            sleep(1000);
            cout<<"PLAYER INPUT: ";
            char y[5];
            cin>>y;
            if(strcmp(y,"YES")==0)
            {
                float g;
                srand(time(0));
                x=((double) rand() / (RAND_MAX));
                x=((double) rand() / (RAND_MAX));
                x=((double) rand() / (RAND_MAX));
                x=((double) rand() / (RAND_MAX));
                g=x*100;
                if(g>40)
                {
                    sleep(1000);
                    cout<<"The ANIMAL was successful TAMED!"<<endl;
                    sleep(1000);
                    health-=10;
                    cout<<"YOUR CURRENT HEALTH IS :"<<health<<endl<<endl;
                    sleep(1000);
                    cout<<"\n\n\nDo you wish to try and kill your tamed animal for food?\n";
                    cout<<"JUST REMEMBER, YOU NEED FOOD TO SURVIVE, AND KILLING YOUR TAMED ANIMAL IS THE ONLY WAY YOU GET FOOD!\n";
                    cout<<"PLAYER INPUT: ";
                    char p[5];
                    cin>>p;
                    if(strcmp(p,"YES")==0)
                    {
                        float q,t;
                        srand(time(0));
                        x=((double) rand() / (RAND_MAX));
                        x=((double) rand() / (RAND_MAX));
                        x=((double) rand() / (RAND_MAX));
                        x=((double) rand() / (RAND_MAX));
                        t=(x*100);
                        sleep(1000);
                        cout<<"\nThe probability of winning the combat against your animal is: "<<t<<"%"<<endl<<endl;
                        sleep(1000);
                        cout<<"\nARE YOU SURE YOU WANT TO PROCEED KEEPING THE PROBABLILITY IN MIND?\n\n ALSO REMEMBER THAT IF YOU WIN THE COMBAT YOUR HEALTH INCREASES BY 30\n\tAND IF YOU ARE DEFEATED, \n\tYOUR HEALTH REDUCES BY 20..\n\tSO TREAD CAREFULLY!!\n";
                        sleep(1000);
                        cout<<"PLAYER INPUT: ";
                        srand(time(0));
                        x=((double) rand() / (RAND_MAX));
                        x=((double) rand() / (RAND_MAX));
                        x=((double) rand() / (RAND_MAX));
                        x=((double) rand() / (RAND_MAX));
                        q=(x*100);
                        char y[5];
                        cin>>y;
                        if(strcmp(y,"YES")==0)
                        {
                            if(q>50)
                            {
                                sleep(1000);
                                cout<<"THE COMBAT WAS SUCCESSFUL, AND YOU GOT A LOT OF FOOD!"<<endl;
                                health+=30;
                                sleep(1000);
                                cout<<"YOUR CURRENT HEALTH IS :"<<health<<endl;
                            }
                            else
                            {
                                sleep(1000);
                                cout<<"The COMBAT WAS NOT SUCCESSFUL!..BETTER LUCK NEXT TIME"<<endl;
                                health-=20;
                                sleep(1000);
                                cout<<"YOUR CURRENT HEALTH IS :"<<health<<endl;
                            }
                        }   
                    }
                }
                else
                {
                    sleep(1000);
                    cout<<"The TAMING OF THE ANIMAL was NOT successful!"<<endl;
                    sleep(1000);
                    health-=10;
                    cout<<"YOUR CURRENT HEALTH IS :"<<health<<endl;
                }
            }
        }
};
int main()
{
	srand(time(0));
	escape player;
	player.display();
	if(strcmp(player.location,"ARCTIC")==0)
	{
	    arctic a;
	    while(a.health>0)
	    {
		a.move();
		while(a.health>0)
		{`
		    a.getanimal();
		}
	    }
	    cout<<"\n\n\n\n\t\t\tSORRY BUT YOU WEREN'T MEANT TO SURVIVE IN THE JUNGLE!\n\n\n";
	}
	else if(strcmp(player.location,"DESERT")==0)
	{
	    desert a;
	    while(a.health>0)
	    {
		a.move();
		while(a.health>0)
		{
		    a.getanimal();
		}
	    }
	    cout<<"\n\n\n\n\t\t\tSORRY BUT YOU WEREN'T MEANT TO SURVIVE IN THE JUNGLE!\n\n\n";
	}   
	else if(strcmp(player.location,"OCEAN")==0)
	{
	    ocean a;
	    while(a.health>0)
	    {
		a.move();
		while(a.health>0)
		{
		    a.getanimal();
		}
	    }
	    cout<<"\n\n\n\n\t\t\tSORRY BUT YOU WEREN'T MEANT TO SURVIVE IN THE JUNGLE!\n\n\n";
	}
	else
	{
	    tropical a;
	    while(a.health>0)
	    {
		a.move();
		while(a.health>0)
		{
		    a.getanimal();
		}
	    }
	    cout<<"\n\n\n\n\t\t\tSORRY BUT YOU WEREN'T MEANT TO SURVIVE IN THE JUNGLE!\n\n\n";
	}
	/*int n,i;
	i=1;
	while(i==1)
	{
		animal c1;
		cout<<"Enter 1 to add an animal\n";
		cout<<"Enter 2 to display all animals\n";
		cout<<"Enter 3 to display a particular record\n";
		cin>>n;
		switch(n)
		{
			case 1:c1.create(); 
			break;
			case 2: c1.displayall();
			break;
			case 3: c1.search();
			break;
		}
		cout<<"Do you want to perform another operation?..press 1 to continue or any other number to exit the program\n";
		cin>>i;
	}*/
   	return 0;
}
