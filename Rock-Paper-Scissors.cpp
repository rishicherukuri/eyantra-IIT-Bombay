#include<bits/stdc++.h>
#include<time.h>

using namespace std;

string userin()
{
    string user_choice;

    cout << "Enter your play: ";

    cin>> user_choice;

    if(user_choice == "r" || user_choice == "p" || user_choice == "s")
    {
        return user_choice;
    }
    else
    {
        cout << "You play should be r (or) p (or) s"<< endl;
        user_choice = userin();
    }

    return user_choice;
}


int main()
{
    srand(time(0));

    string rps[] = {"r", "p", "s"};
    string comp_choice, user_choice;
    int comp_score = 0, player_score = 0;

    char cont;

    while(true)
    {
        user_choice = userin();

        comp_choice = rps[rand()%3];

        if(comp_choice == user_choice)
        {
            cout << "Game is a Tie"<< endl;
        }
        else
        {
            if (user_choice == "r")
            {
                if(comp_choice == "s")
                {
                    ++player_score;
                    cout << "You won !! Computer chose SCISSORS"<< endl;
                }
                else
                {
                    ++comp_score;
                    cout << "  ):  computer won, it chose PAPER"<< endl;
                }
            }
            else if(user_choice == "p")
            {
                if(comp_choice == "r")
                {
                    ++player_score;
                    cout << "You won the game!! Computer chose ROCK"<< endl;
                }
                else
                {
                    ++comp_score;
                    cout << "  ):  computer won, it chose SCISSORS"<< endl;
                }
            }
            else
            {
                if(comp_choice == "p")
                {
                    ++player_score;
                    cout << "You won the game!! Computer chose PAPER"<< endl;
                }
                else
                {
                    ++comp_score;
                    cout << "  ):  computer won, it chose ROCK"<< endl;
                }
            }
        }

        cout << "Enter  'y'  to start again, anything to close and show SCORES => ";

        cin >> cont;

        system("CLS");

        if(cont != 'y')
        {
            cout<< "YOUR SCORE ==>  "<< player_score<< endl;
            cout<< "COMPUTER SCORE ==>  "<< comp_score<< endl;

            if (comp_score < player_score)
            {
                cout << "YOU WON THIS SESSION "<< endl;
            }
            else if (comp_score > player_score)
            {
                cout << "HARD LUCK COMPUTER HAD A GOOD TIME "<< endl;
            }
            else
            {
                cout << "NECK--TO--NECK"<< endl;
            }


            break;
        }

    }

}
