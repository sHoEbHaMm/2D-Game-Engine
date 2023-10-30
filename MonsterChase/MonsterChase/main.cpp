#include<iostream>
#include<stdio.h>
#include<conio.h>
#include "cpy.h"
#include "Point2D.h"

#define Print(x) std :: cout << x;
#define Println(x) std :: cout << x << std :: endl;

const char* MonsterNames[50] = { "Drifloon", "Gengar", "Cacturne", "Dusclops", "Honedge", "Shakal", "Haiwan", "TatyaBicchu", "Kancha",
"Odour", "Shaitaan", "Diabolos", "Vampire", "Vader", "Demon", "Sniper", "Doom", "RedFly", "Drangon", "Grimer", "Cyclone", "Vex", "Safari",
"Ditch", "Blink", "Whistler", "Venom", "Omega", "Apex", "Crypto", "Trace", "Schism", "Longshot", "Drifter", "Mimic", "Plague", "Slicer",
"Bipolar", "Oblique", "Inferno", "Psycho", "BlackOut", "Killer", "Recluse", "SiriusBlack", "Voldemort", "Matrix", "Meowth", "Direwolf",
"Kio"};

     bool play = true;

class Actor
{
	int n = 50;
public:

	Actor() {

		name = (char*)malloc(n * sizeof(char));
	}

	~Actor()
	{
		free(name);
	}
	char* name;
	Point2D point_num;
};

void InitEnemy(Actor* actor)
{
	char* name;
	char t_name[50];
	int i = 0;
	size_t len = 0;
	i = rand() % 50;

	strcpy_s(t_name, MonsterNames[i]);
	len = strlen(t_name);

	name = new char[len + 1];
	cpy(name, t_name, len + 1);
	name[len] = 0;
	free(actor->name);
	actor->name = name;
	actor->point_num.SetX(rand() % 201);
	actor->point_num.SetY(rand() % 201);
}

typedef struct Node
{
	Actor* actor;
	Node* next;
}* nodePtr;
nodePtr head = NULL;
nodePtr curr = NULL;
//nodePtr temp = NULL;

void AddEnemy(Actor* actor)
{
	InitEnemy(actor);
	nodePtr newnode = new Node();
	newnode->next = NULL;
	newnode->actor = actor;

	if (head != NULL) //if already exsting list
	{
		curr = head;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = newnode;
	}
	else
	{
		head = newnode;
	}
}

void DelEnemy(nodePtr head)
{
	if (head == NULL)
	{
		Println("No more enemies left!!");
		play = false;
	}	
	else if (head->next == NULL)
	{
		Println("All Enemies defeated!!");
		head->actor->~Actor();
		delete head;
		head = NULL;
		play = false;
	}
	else
	{
		nodePtr temp = head;
		nodePtr temp2 = head;

		while (temp->next != NULL)
		{
			temp2 = temp;
			temp = temp->next;
		}
		temp2->next = NULL;
		temp->next = NULL;
		temp->actor->~Actor();
		temp = NULL;
	}
}

void DisplayEnemies()
{
	curr = head;
	while (curr != NULL)
	{
		Println(curr->actor->name << " is at " << "[" << curr->actor->point_num.GetX() << ", " << curr->actor->point_num.GetY() << "]");
		curr = curr->next;
	}
}

void MoveEnemies()
{
	curr = head;
	int n = (rand() % 21) - 10;
	while (curr != NULL)
	{
		curr->actor->point_num.SetX(curr->actor->point_num.GetX() + n);
		curr->actor->point_num.SetY(curr->actor->point_num.GetY() + n);
		curr = curr->next;
	}
}

void deleteList(Node* head_ref)
{

	/* deref head_ref to get the real head */
	Node* current = head_ref;
	Node* next = NULL;

	while (current != NULL)
	{
		next = current->next;
		current->actor->~Actor();
		//delete current->actor;
		current = next;
	}

	/* deref head_ref to affect the real head back
		in the caller. */
	head_ref = NULL;
}

void Play(Actor & myPlayer)
{
	Actor* actor = new Actor();
	Println("Player : ");
	Println(myPlayer.name << " is at [" << myPlayer.point_num.GetX() << ", " << myPlayer.point_num.GetY() << "]");
	Println("");
	MoveEnemies();
	Println("Enemies : ");
	DisplayEnemies();
	Println("");
	Println("Use WASD to move your player or 'Q' to quit");
	int input = _getch();

	int num = rand() % 50;
	if (num > 25)
	{
		AddEnemy(actor);
	}
	else
	{
		delete actor;
		DelEnemy(head);
	}

	if (65 == input || 97 == input)
	{
		//Println("A is pressed");
		myPlayer.point_num.SetX(myPlayer.point_num.GetX() - 1);
	}
	else if (68 == input || 100 == input)
	{
		//Println("D is pressed");
		myPlayer.point_num.SetX(myPlayer.point_num.GetX() + 1);
	}
	else if (87 == input || 119 == input)
	{
		//Println("W is pressed");
		myPlayer.point_num.SetY(myPlayer.point_num.GetY() + 1);
	}
	else if (83 == input || 115 == input)
	{
		//Println("S is pressed");
		myPlayer.point_num.SetY(myPlayer.point_num.GetY() - 1);
	}
	else if (81 == input || 113 == input)
	{
		//Println("Q is pressed");
		Println("Thanks for playing");
		Println("");
		play = false;
		_CrtDumpMemoryLeaks();
	}
}

int main()
{
	Actor myPlayer;
	char p_name[50];
	char* temp;
	int initMonsCount;

	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Println("Welcome to MonsterChase!");
	Println(" ");

	Print("Enter player name : ");
	std::cin >> p_name;
	size_t len = strlen(p_name);
	cpy(myPlayer.name, p_name);
	
	myPlayer.name[len] = 0;

	temp = (char*)realloc(myPlayer.name, len + 1);
	if (temp != NULL)
	{
		myPlayer.name = temp;
	}

	Print("How many monsters do you want to start with ? : ");
	std :: cin >> initMonsCount;
	
	for (int a = 1; a <= initMonsCount; a++)
	{
		Actor* actor = new Actor();
		AddEnemy(actor);
	}
	myPlayer.point_num.SetX(rand() % 100);
	myPlayer.point_num.SetY(rand() % 100);

	while (true)
	{
		if (play)
		{
			Play(myPlayer);
		}
		else
		{
			deleteList(head);
			myPlayer.~Actor();
			break;
		}
	}
	Println("Clearing leaks");
	Println("Cleared");
	exit(0);
	return 0;
}