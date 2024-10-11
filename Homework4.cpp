#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <vector>
#include <limits>
using namespace std;


/*void drawLine(char symbol, int length, bool isVertical, int speed) {
    int delay;

    switch (speed) {
    case 1: delay = 100; break;     // Slow
    case 2: delay = 50; break;      // Normal
    case 3: delay = 10; break;      // Fast
    default: delay = 50; break;
    }

    for (int i = 0; i < length; i++) {
        cout << symbol;
        if (isVertical) cout << endl;
        this_thread::sleep_for(chrono::milliseconds(delay));
    }
    if (!isVertical) cout << endl;
}

int main() {
    char symbol;
    int length, direction, speed;

    cout << "Enter the symbol for the line: ";
    cin >> symbol;

    cout << "Enter the length of the line: ";
    cin >> length;

    cout << "Choose direction (1 - Horizontal, 2 - Vertical): ";
    cin >> direction;

    cout << "Choose speed (1 - Slow, 2 - Normal, 3 - Fast): ";
    cin >> speed;

    bool isVertical = (direction == 2);
    drawLine(symbol, length, isVertical, speed);

    return 0;
}
*/
/*int rollDice() {
    return rand() % 6 + 1;
}

void showRollingAnimation() {
    for (int i = 0; i < 3; i++) {
        cout << "Rolling";
        for (int j = 0; j <= i; j++) {
            cout << ".";
            this_thread::sleep_for(chrono::milliseconds(300));
        }
        cout << "\r"; // Return to the beginning of the line to overwrite
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(300));
        cout << "       \r"; // Clear the line by overwriting with spaces
    }
}

void displayRoundHeader(int round) {
    cout << "\n=============================\n";
    cout << "        Round " << round << "\n";
    cout << "=============================\n";
}

void displayFinalScore(int userTotal, int computerTotal) {
    cout << "\n=====================================\n";
    cout << "            Final Scores             \n";
    cout << "=====================================\n";
    cout << "User:      " << userTotal << "\n";
    cout << "Computer:  " << computerTotal << "\n\n";

    if (userTotal > computerTotal) {
        cout << "🎉 Congratulations! You win! 🎉\n";
    }
    else if (userTotal < computerTotal) {
        cout << "💻 Computer wins! Better luck next time. 💻\n";
    }
    else {
        cout << "It's a tie! 🤝\n";
    }
    cout << "=====================================\n";
}

void displayRoll(int round, const string& player, int roll1, int roll2) {
    displayRoundHeader(round);
    cout << player << "'s turn.\n";
    showRollingAnimation();
    cout << player << " rolled: [" << roll1 << "] and [" << roll2
        << "] -> Total: " << roll1 + roll2 << "\n\n";
    this_thread::sleep_for(chrono::milliseconds(1000));
}

int main() {
    srand(static_cast<unsigned>(time(0)));
    int userTotal = 0, computerTotal = 0;

    cout << "=====================================\n";
    cout << "         🎲 Welcome to Dice Game! 🎲\n";
    cout << "=====================================\n\n";

    for (int round = 1; round <= 3; round++) {
        int userRoll1 = rollDice();
        int userRoll2 = rollDice();
        userTotal += userRoll1 + userRoll2;
        displayRoll(round, "User", userRoll1, userRoll2);

        int computerRoll1 = rollDice();
        int computerRoll2 = rollDice();
        computerTotal += computerRoll1 + computerRoll2;
        displayRoll(round, "Computer", computerRoll1, computerRoll2);

        cout << "-------------------------------------\n";
    }

    displayFinalScore(userTotal, computerTotal);
    return 0;
}*/




/*int main() {
    const int size = 10;
    int arr[size];

    srand(static_cast<unsigned>(time(0)));

    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;  // Random numbers between 0 and 99
        cout << arr[i] << " ";
    }
    cout << endl;

    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    cout << "Minimum element: " << min << endl;
    cout << "Maximum element: " << max << endl;

    return 0;
}*/



/*int main() {
    const int months = 12;
    double profit[months];
    int start, end;

    cout << "Enter the profit for each month:\n";
    for (int i = 0; i < months; i++) {
        cout << "Month " << i + 1 << ": ";
        cin >> profit[i];
    }

    cout << "Enter the range (start and end month, between 1 and 12): ";
    cin >> start >> end;

    if (start < 1 || end > months || start > end) {
        cout << "Invalid range.\n";
        return 1;
    }

    int minMonth = start - 1;
    int maxMonth = start - 1;

    for (int i = start - 1; i < end; i++) {
        if (profit[i] < profit[minMonth]) {
            minMonth = i;
        }
        if (profit[i] > profit[maxMonth]) {
            maxMonth = i;
        }
    }

    cout << "Minimum profit was in month " << minMonth + 1 << " with " << profit[minMonth] << endl;
    cout << "Maximum profit was in month " << maxMonth + 1 << " with " << profit[maxMonth] << endl;

    return 0;
}*/
int main() {
    int N;
    cout << "Enter the number of elements (N): ";
    cin >> N;

    vector<double> arr(N);
    srand(static_cast<unsigned>(time(0)));

    cout << "Array: ";
    for (int i = 0; i < N; i++) {
        arr[i] = (rand() % 201 - 100) / 10.0; 
        cout << arr[i] << " ";
    }
    cout << endl;

    double sumNegative = 0;
    for (double num : arr) {
        if (num < 0) {
            sumNegative += num;
        }
    }

    int minIndex = 0, maxIndex = 0;
    for (int i = 1; i < N; i++) {
        if (arr[i] < arr[minIndex]) minIndex = i;
        if (arr[i] > arr[maxIndex]) maxIndex = i;
    }

    if (minIndex > maxIndex) swap(minIndex, maxIndex);


    double productBetweenMinMax = 1;
    bool foundElementsBetween = false;
    for (int i = minIndex + 1; i < maxIndex; i++) {
        productBetweenMinMax *= arr[i];
        foundElementsBetween = true;
    }
    if (!foundElementsBetween) productBetweenMinMax = 0; 

  
    double productEvenIndex = 1;
    for (int i = 0; i < N; i += 2) {
        productEvenIndex *= arr[i];
    }

    
    int firstNegative = -1, lastNegative = -1;
    for (int i = 0; i < N; i++) {
        if (arr[i] < 0) {
            if (firstNegative == -1) {
                firstNegative = i;
            }
            lastNegative = i;
        }
    }

    double sumBetweenNegatives = 0;
    if (firstNegative != -1 && lastNegative != -1 && firstNegative < lastNegative) {
        for (int i = firstNegative + 1; i < lastNegative; i++) {
            sumBetweenNegatives += arr[i];
        }
    }
    else {
        sumBetweenNegatives = 0; 
    }

   
    cout << "Sum of negative elements: " << sumNegative << endl;
    cout << "Product of elements between min and max elements: "
        << (foundElementsBetween ? productBetweenMinMax : 0) << endl;
    cout << "Product of elements with even indices: " << productEvenIndex << endl;
    cout << "Sum of elements between first and last negative elements: " << sumBetweenNegatives << endl;

    return 0;
}