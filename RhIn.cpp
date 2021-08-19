#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;


class Human
{
	
	public:
   Human()
   {
	   cout<<"Конструктор класса human"<<endl;
   };
		
	void Show()
	{
	cout<<"Имя\t"<<this->name<<"\nГендер\t"<<this->gender<<"\nЦв глаз\t"<<this->eyecolor<<"\nРост\t"<<this->rost<<"\nВес\t"<<this->wes<<endl<<endl;
	};
	
	string Getcolor()
	{
		return this->eyecolor;
	};
		
	string Getgender()
	{
		return this->gender;
	};
	
	int Getrost()
	{
		return this->rost;
	};
	
	int Getwes()
	{
		return this-wes;
	};
	
	protected:
	string gender;
	string name;
	string eyecolor;
	int rost;
	int wes;
		
};


class Woman : public virtual Human
{
	public:
	
	
	Woman()
	{
	    this->name = "нет данных";
		this->eyecolor = "нет данных";
		this->rost = 0;
		this->wes = 0;
		this->gender="Девушка";
	}
	Woman (string name):Woman()
	{
		this->name = name;
	};
		Woman (string name, string eyecolor ):Woman(name)
	{
		this->eyecolor = eyecolor;
	};
		Woman (string name, string eyecolor, int rost):Woman(name, eyecolor)
	{
		this->rost = rost ;
	};
	Woman (string name, string eyecolor , int rost , int wes): Woman (name, eyecolor , rost )
	{
		this->wes=wes;
	};
	
	void Love(Human &other)
	{
		cout<<"Я влюбилась в его  "<<other.Getcolor()<<" глаза!"<<endl;
	};

	private:
	protected:
};


class Man:  public virtual Human
{
	public:
		Man()
	{
	    this->name = "нет данных";
		this->eyecolor = "нет данных ";
		this->rost = 0;
		this->wes = 0;
		this->gender="Парень";
	}
	Man (string name):Man()
	{
		this->name = name;
	};
		Man (string name, string eyecolor ):Man(name)
	{
		this->eyecolor = eyecolor;
	};
		Man (string name, string eyecolor, int rost):Man(name,  eyecolor)
	{
		this->rost = rost ;
	};
	Man (string name,string eyecolor , int rost , int wes): Man (name,  eyecolor , rost )
	{
		this->wes=wes;
	};
	
	void Love(Human &other)
	{
		cout<<"Я влюбился в её "<<other.Getcolor()<<" глаза!"<<endl;
	};
	
	private:
	protected:
};



class Child: public Woman, public Man
{
	public:
	Child(string sname, Woman &Mom, Man &Dad)
	{
	this->name=sname;
	
	if (Randfoo())
	{
		 this->gender=Dad.Getgender();
	} else this->gender=Mom.Getgender();

	if (Randfoo())
	{
		 this->eyecolor=Dad.Getcolor();
	} else this->eyecolor=Mom.Getcolor();
	
	if (Randfoo())
	{
		 this->wes=Dad.Getwes();
	} else this->wes=Mom.Getwes();
    
	
	if (Randfoo())
	{
		 this->rost=Dad.Getrost();
	} else this->rost=Mom.Getrost();
	
	
	
	};
	
	bool Randfoo()
	{
		bool res;
		if ((rand()/2)==0) res=0;
		else res=1;
		
		return res;
	};
	
	private:
	protected:
};

int main()
{
    Woman Nika("Ника", "почти_зеленые", 161, 80);
	Nika.Show();
	
	Man Nikita("Никита","синие", 180  ,80 );
	Nikita.Show();
	
	Child Kira("Саша", Nika , Nikita);
	Kira.Show();
     return 0;
}



