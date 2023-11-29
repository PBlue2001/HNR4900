/*
In case anyone sees this code
Parker Blue
honors midterm project 4900

*/
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

void pause() {
    cout << "Press Enter to continue...(may need to hit it twice)";
    cin.get();
    cin.ignore();
}

void introduction() {
    cout << "Welcome to the Honors Reflection Game!" << endl;
    cout << "You will embark on a journey to make choices that impact your learning, growth, and self-reflection." << endl;
    pause();
}

void grow() {
    cout << "You've chosen to focus on personal growth." << endl;
    cout << "Select a growth activity:" << endl;
    cout << "1. Join a fitness program" << endl;
    cout << "2. Start a reading challenge" << endl;
    cout << "3. Learn a new language" << endl;
    cout << "4. Reflect on your past and find areas where you would like to improve" << endl;

    int choice;
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "You've chosen to join a fitness program." << endl;
        cout << "Regular exercise is essential for physical and mental well-being." << endl;
        break;
    case 2:
        cout << "You've chosen to start a reading challenge." << endl;
        cout << "Reading can expand your knowledge and imagination." << endl;
        break;
    case 3:
        cout << "You've chosen to learn a new language." << endl;
        cout << "Learning a new language can open up new opportunities and cultures." << endl;
        break;
    case 4:
        cout << "Identifying ones shortcomings, either personal or otherwise is a huge step towards future growth." <<
            " Reflect on a moment of hardship to see how a new and better you could have handled that situation." << endl;
        break;
    default:
        cout << "Invalid choice. Please choose a valid option." << endl;
    }

    pause();
}
void developEmotionally() {
    cout << "Emotional Development:" << endl;
    cout << "Emotional development involves understanding and managing your feelings." << endl;
    pause();

    cout << "Exercise: Practice Mindfulness" << endl;
    cout << "Take a few minutes to practice mindfulness meditation to enhance emotional awareness." << endl;
    pause();

    cout << "Why Emotional Development Matters:" << endl;
    cout << "Being emotionally intelligent can improve relationships and mental well-being." << endl;
    pause();

    cout << "I have learned in class not only to take inventory of where I stand, but how to further develop myself."<<
        " Understanding where you are is the first step to finding out your potential, and the ability to see both sides of a situation will help immensely." << endl;
    pause();
}

void developIntellectually() {
    cout << "Intellectual Development:" << endl;
    cout << "Intellectual development involves expanding your knowledge and critical thinking skills." << endl;
    pause();

    cout << "Exercise: Solve a Puzzle" << endl;
    cout << "Challenge yourself with a puzzle or brain-teaser to enhance your problem-solving abilities. I recommend Wordle." << endl;
    pause();

    cout << "Why Intellectual Development Matters:" << endl;
    cout << "Intellectual growth can lead to better decision-making and a deeper understanding of the world." << endl;
    pause();

    cout << "Reflecting on how we got to where we are today involves reviewing a large amount of our intellectual work up to this point. " <<
        "After reviewing my collection, the ability to see what is important and what is not is critical to self reflection and identifying where improvements can be made." << endl;
    pause();
}

int main() {
    introduction();

    while (true) {
        cout << "What would you like to focus on? (Type the Number)" << endl;
        cout << "1. Growth" << endl;
        cout << "2. Emotional Development" << endl;
        cout << "3. Intellectual Development" << endl;
        cout << "4. Quit" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            grow();
            break;
        case 2:
            developEmotionally();
            break;
        case 3:
            developIntellectually();
            break;
        case 4:
            cout << "Thanks for playing! Goodbye." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please choose a valid option." << endl;
        }
    }

    return 0;
}
