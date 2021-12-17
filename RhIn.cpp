#include <iostream>
#include <ctime>
#include <string>

using namespace std;

/*
* Родительский класс Human
* содержит информацию о имени, цвете глаз, росте и весе.
*/
class Human
	{
		public:
		Human()
		   {
			   cout<<"Запущен конструктор класса human"<<endl;
		   };
		void Show()
			{
			cout<<"Имя\t"<<this->name<<"\nГендер\t"<<this->gender<<"\nЦв глаз\t"<<this->eyecolor<<"\nРост\t"<<this->height<<"\nВес\t"<<this->weight<<endl<<endl;
			};
		
		string Getcolor()
			{
				return this->eyecolor;
			};
		int Getheight()
			{
				return this->height;
			};
		int Getweight()
			{
				return this->weight;
			};
		
		protected:
		string gender;
		string name;
		string eyecolor;
		int height;
		int weight;
	};
/*
* Дочерние классы Man и Woman содержат инфрмацию о гендере.
* Имею комплекс делигирующих конструкторов для заполнения полей класса Human полностью или частично.
*/
class Woman : public virtual Human
	{
		public:
		Woman()
			{
			    this->name = "нет данных";
				this->eyecolor = "нет данных";
				this->height = 0;
				this->weight = 0;
				this->gender = "Девушка";
			}
		Woman (string name):Woman()
			{
				this->name = name;
			};
		Woman (string name, string eyecolor ):Woman(name)
			{
				this->eyecolor = eyecolor;
			};
		Woman (string name, string eyecolor, int height):Woman(name, eyecolor)
			{
				this->height = height ;
			};
		Woman (string name, string eyecolor , int height , int weight): Woman (name, eyecolor , height )
			{
				this->weight=weight;
			};
		string Getgender()
			{
				return this->gender;
			};
	};

class Man:  public virtual Human
	{
		public:
		Man()
			{
			    this->name = "нет данных";
				this->eyecolor = "нет данных ";
				this->height = 0;
				this->weight = 0;
				this->gender = "Парень";
			}
		Man (string name):Man()
			{
				this->name = name;
			};
		Man (string name, string eyecolor ):Man(name)
			{
				this->eyecolor = eyecolor;
			};
		Man (string name, string eyecolor, int height):Man(name,  eyecolor)
			{
				this->height = height ;
			};
		Man (string name,string eyecolor , int height , int weight): Man (name,  eyecolor , height )
			{
				this->weight=weight;
			};
		string Getgender()
			{
				return this->gender;
			};
	};


/*
* Класс Child получен путём ромбовидного наследования от классов Woman и Man
* Класс имеет доступ к функциям класса Human и может оперировать информацией хранящейся в классах Woman и Man
*/
class Child: public Woman, public Man
	{
		public:
		Child(string sname, Woman &Mom, Man &Dad)
			{
				this->name = sname;
				if (Randfoo()) this->gender=Dad.Getgender();
					else this->gender=Mom.Getgender();
				if (Randfoo()) this->eyecolor=Dad.Getcolor();
					else this->eyecolor=Mom.Getcolor();
				if (Randfoo()) this->weight=Dad.Getweight();
					else this->weight=Mom.Getweight();
				if (Randfoo()) this->height=Dad.Getheight();
					else this->height=Mom.Getheight();
			};
		bool Randfoo()
			{
				return rand() % 2;
			};
	};

int main()
	{
		srand(time(0));
	    Woman Maria("Мария", "почти_зеленые", 161, 55);
		Maria.Show();
		
		Man Stepan("Степан","синие", 180  ,80 );
		Stepan.Show();
		
		Child Kira("Саша", Maria, Stepan);
		Kira.Show();
	     return 0;
	}



