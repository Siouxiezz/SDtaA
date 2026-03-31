#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

struct Music
{
    string container, name, author;
    float time;
    int quantity;
    float price;
};

struct Stack
{
    Music data;
    Stack* next;
};

void push(Stack*& first, Music m)
{
    Stack* s = new Stack;
    s -> data = m;
    s -> next = first;
    first = s;
}

Music pop(Stack*& first)
{
    Music empty;

    if(!first)
    {
        return empty;
    }

    Stack* s = first;
    Music val = s -> data;
    first = first -> next;

    delete s;

    return val;
}

Music top(Stack* first)
{
    if(!first)
    {
        Music empty;
        return empty;
    }

    return first -> data;
}

int size(Stack* first)
{
    int count = 0;

    while(first)
    {
        count++;
        first = first -> next;
    }

    return count;
}

bool isEmpty(Stack* first)
{
    return first == 0;
}

int main()
{
    string searchArtist;
    double totalTime = 0, cassetteSum = 0;
    Stack* catalog = 0;
    Stack* cassette = 0;

    push(catalog, {"Vinyl record", "Stairway_to_Heaven", "Led Zeppelin", 8.02, 9, 500.0});
    push(catalog, {"Audio cassette", "Thriller", "Michael Jackson", 4.19, 9, 150.0});
    push(catalog, {"Audio cassette", "Billie_Jean", "Michael Jackson", 4.54, 1, 150.0});
    push(catalog, {"Laser Disc", "Smells_like_Teen_Spirit", "Nirvana", 5.01, 1, 300.0});
    push(catalog, {"Audio cassette", "Thriller", "Michael Jackson", 5.57, 1, 180.0});

    cout << "Enter artist: ";
    getline(cin, searchArtist);

    while(!isEmpty(catalog))
    {
        Music m = top(catalog);
        pop(catalog);

        if(m.author == searchArtist)
        {
            totalTime += m.time;
        }
        
        if(m.container == "Audio cassette")
        {
            push(cassette, m);
            cassetteSum += m.price;
        }
    }

    cout << "Duration time " << searchArtist << ": " << totalTime << " min." << endl;
    if (!isEmpty(cassette)) {
        cout << "Average sum of cassetes: " << cassetteSum / size(cassette) << "$" << endl;
    }

    getch();

    return 0;
}