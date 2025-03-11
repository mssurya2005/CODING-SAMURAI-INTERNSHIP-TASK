#include<iostream>
#include<cstdlib>
using namespace std;

int main(){

	// Providing a seed value
	srand((unsigned) time(NULL));
    int chances = 7;
    int guess_counter = 0;
    int random = 0 + (rand() % 101);
    int guess;
	// Loop to get 5 random numbers
	while (guess_counter <= chances){
		guess_counter+=1;
		// Retrieve a random number between 100 and 200
		// Offset = 100
		// Range = 101
		cout<<"\n Please enter your guess : ";
		cin>>guess;
	    if (guess == random){
	        cout<<"\t Your guess is absolutly right!!!";
	        break;
	    }
	    else if (guess_counter >= chances && guess != random){
	        cout<<"\t Oops, the number is "<<random<<". Better Luck Next Time...";
	        break;
	    }
	    else if (guess < random){
	        cout<<"\t Your Guess is Too Low"<<endl;
	    }
	    else if(guess > random){
	        cout<<"\t Your Guess is Too High"<<endl;
	    }
	}

	return 1;
}