#include <iostream>
using namespace std;

class Stack {
    private:
        int top;
        string arr[100]; 

    public:
        Stack() { top = -1; }

        bool push(string c) {
            if (top >= 99) {
                cout << "Stack overflow\n";
                return false;
            } else {
                arr[++top] = c;
                return true;
            }
        }

        string pop() {
            if (top < 0) {
                cout << "Stack underflow\n";
                return "";
            } else {
                string c = arr[top--];
                return c;
            }
        }

        bool isEmpty() {
            return (top < 0);
        }
};

bool isMatchingPair(string open, string close) {
    if (open == "(" && close == ")") return true;
    if (open == "[" && close == "]") return true;
    if (open == "{" && close == "}") return true;
    if (open == "<" && close == ">") return true;
    if (open == "<<" && close == ">>") return true;
    return false;
}

int main() {
    string input;
    //cout << "Enter a string: ";
    getline(cin, input);

    Stack s;
    int matchedCount = 0;

    for (int i = 0; i < input.length(); i++) {
        string current(1, input[i]);

        if (current == "<" && i + 1 < input.length() && input[i + 1] == '<') {
            s.push("<<");
            i++; 
        } else if (current == ">" && i + 1 < input.length() && input[i + 1] == '>') {
            if (s.isEmpty() || s.pop() != "<<"){//ค่าที่pop ต้องเป็น <<
                cout << "Not matched\n" << matchedCount << " matched\n";
                return 0;
            } else {
                matchedCount++;
                i++; 
            }
        } else if (current == "(" || current == "[" || current == "{" || current == "<") {
            s.push(current);
        } else if (current == ")" || current == "]" || current == "}" || current == ">") {
            if (s.isEmpty()) {
                cout << "Not matched\n" << matchedCount << " matched\n";
                return 0;
            }

            string top = s.pop();
            //top คือค่าที่ pop ไป ex  ) ] } >
            if (isMatchingPair(top, current)) {
                matchedCount++;
            } else {
                cout << "Not matched\n" << matchedCount << " matched\n";
                return 0;
            }
        }
    }

    if (s.isEmpty()) {
        cout << matchedCount << " matched\n";
    } else {
        cout << "Not matched\n" << matchedCount << " matched\n";
    }

    return 0;
}
