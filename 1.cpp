#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class FiniteAutomaton
{
private:
public:
    unordered_map<int, unordered_map<char, int>> transitions;
    int initialState;
    unordered_set<int> finalStates;
    FiniteAutomaton() : initialState(-1) {}

    void setInitialState(int state)
    {
        initialState = state;
    }

    void addTransition(int fromState, char input, int toState)
    {
        transitions[fromState][input] = toState;
    }

    void addFinalState(int state)
    {
        finalStates.insert(state);
    }

    bool isAccepted(const string &input) const
    {
        if (initialState == -1)
        {
            cerr << "Initial state is not set." << endl;
            return false;
        }

        int currentState = initialState;

        for (char c : input)
        {
            auto stateTransitions = transitions.find(currentState);
            if (stateTransitions == transitions.end())
            {
                return false;
            }

            auto nextState = stateTransitions->second.find(c);
            if (nextState == stateTransitions->second.end())
            {
                return false;
            }

            currentState = nextState->second;
        }

        return finalStates.find(currentState) != finalStates.end();
    }
void printTransitionTable() const {
        cout << "Transition Table:" << endl;
        cout<<"State"<<"\t"<<"Input"<<"\t"<<"Next State"<<endl;
        for (const auto &state : transitions) {
            for (const auto &trans : state.second) {
                cout << state.first << "\t" << trans.first << "\t" << trans.second << endl;
            }
        }
        cout << endl;
    }
};

// FA1: Accepts strings with three consecutive 1's
void runFA1()
{
    FiniteAutomaton fa;
    const int q0 = 0, q1 = 1, q2 = 2, q3 = 3;

    fa.setInitialState(q0);
    fa.addTransition(q0, '0', q0);
    fa.addTransition(q0, '1', q1);
    fa.addTransition(q1, '0', q0);
    fa.addTransition(q1, '1', q2);
    fa.addTransition(q2, '0', q0);
    fa.addTransition(q2, '1', q3);
    fa.addTransition(q3, '0', q3);
    fa.addTransition(q3, '1', q3);
    fa.addFinalState(q3);

    string input;
    cout << "Enter input string for FA1 that accepts strings with three consecutive 1's: ";
    cin >> input;

    cout << (fa.isAccepted(input) ? "Accepted" : "Not Accepted") << endl;
}

// FA2: Accepts strings with exactly two or three 1's
void runFA2()
{
    FiniteAutomaton fa;
    const int q0 = 0, q1 = 1, q2 = 2, q3 = 3, q4 = 4;

    fa.setInitialState(q0);
    fa.addTransition(q0, '0', q0);
    fa.addTransition(q0, '1', q1);
    fa.addTransition(q1, '0', q1);
    fa.addTransition(q1, '1', q2);
    fa.addTransition(q2, '0', q2);
    fa.addTransition(q2, '1', q3);
    fa.addTransition(q3, '0', q3);
    fa.addTransition(q3, '1', q4);
    fa.addTransition(q4, '0', q4);
    fa.addTransition(q4, '1', q4);
    fa.addFinalState(q2);
    fa.addFinalState(q3);

    string input;
    cout << "Enter input string for FA2 that accepts strings with exactly two or three 1's (Interpretation 1: Not consecutive)";
    cin >> input;

    cout << (fa.isAccepted(input) ? "Accepted" : "Not Accepted") << endl;
}
void runFA3()
{
    FiniteAutomaton fa;
    const int q0 = 0, q1 = 1, q2 = 2, q3 = 3, q4 = 4;

    fa.setInitialState(q0);
    fa.addTransition(q0, '0', q0);
    fa.addTransition(q0, '1', q1);
    fa.addTransition(q1, '0', q4);
    fa.addTransition(q1, '1', q2);
    fa.addTransition(q2, '0', q4);
    fa.addTransition(q2, '1', q3);
    fa.addTransition(q3, '0', q3);
    fa.addTransition(q3, '1', q4);
    fa.addTransition(q4, '0', q4);
    fa.addTransition(q4, '1', q4);
    fa.addFinalState(q2);
    fa.addFinalState(q3);

    string input;
    cout << "Enter input string for FA2 that accepts strings with exactly two or three 1's (Interpretation 2: consecutive)";
    cin >> input;

    cout << (fa.isAccepted(input) ? "Accepted" : "Not Accepted") << endl;
}

// FA3: Accepts strings of length 4 or more with the first two characters the same as the last two
void runFA4()
{
    FiniteAutomaton fa;
    const int q0 = 0, q1 = 1, q2 = 2, q3 = 3, q4 = 4, q5 = 5, q6 = 6, q7 = 7, q8 = 8, q9 = 9, q10 = 10, q11 = 11, q12 = 12, q13 = 13, q14 = 14;

    fa.setInitialState(q0);

    fa.addTransition(q0, 'a', q1);
    fa.addTransition(q0, 'b', q8);
    fa.addTransition(q1, 'a', q2);
    fa.addTransition(q1, 'b', q5);
    fa.addTransition(q2, 'a', q3);
    fa.addTransition(q2, 'b', q2);
    fa.addTransition(q3, 'a', q4);
    fa.addTransition(q3, 'b', q2);
    fa.addTransition(q4, 'a', q4);
    fa.addTransition(q4, 'b', q2);
    fa.addTransition(q5, 'a', q6);
    fa.addTransition(q5, 'b', q5);
    fa.addTransition(q6, 'a', q6);
    fa.addTransition(q6, 'b', q7);
    fa.addTransition(q7, 'a', q6);
    fa.addTransition(q7, 'b', q5);
    fa.addTransition(q8, 'a', q9);
    fa.addTransition(q8, 'b', q12);
    fa.addTransition(q9, 'a', q9);
    fa.addTransition(q9, 'b', q10);
    fa.addTransition(q10, 'a', q11);
    fa.addTransition(q10, 'b', q10);
    fa.addTransition(q11, 'a', q9);
    fa.addTransition(q11, 'b', q10);
    fa.addTransition(q12, 'a', q12);
    fa.addTransition(q12, 'b', q13);
    fa.addTransition(q13, 'a', q12);
    fa.addTransition(q13, 'b', q14);
    fa.addTransition(q14, 'a', q12);
    fa.addTransition(q14, 'b', q14);

    fa.addFinalState(q4);
    fa.addFinalState(q7);
    fa.addFinalState(q11);
    fa.addFinalState(q14);

    string input;
    cout << "Enter input string for FA3: ";
    cin >> input;

    cout << (fa.isAccepted(input) ? "Accepted" : "Not Accepted") << endl;
}

// FA4: Accepts strings where the language is a(a+b)*b
void runFA5()
{
    FiniteAutomaton fa;
    const int q0 = 0, q1 = 1, q2 = 2;

    fa.setInitialState(q0);
    fa.addTransition(q0, 'a', q1);
    fa.addTransition(q1, 'a', q1);
    fa.addTransition(q1, 'b', q2);
    fa.addTransition(q1, 'a', q1);
    fa.addTransition(q2, 'a', q1);
    fa.addTransition(q2, 'b', q2);
    fa.addFinalState(q2);

    string input;
    cout << "Enter input string for FA4: ";
    cin >> input;

    cout << (fa.isAccepted(input) ? "Accepted" : "Not Accepted") << endl;
}

// FA5: Accepts strings for EVEN-EVEN
void runFA6()
{
    FiniteAutomaton fa;

    const int q0 = 0; // even a, even b
    const int q1 = 1; // even a, odd b
    const int q2 = 2; // odd a, even b
    const int q3 = 3; // odd a, odd b

    fa.setInitialState(q0);

    fa.addTransition(q0, 'a', q2);
    fa.addTransition(q0, 'b', q1);
    fa.addTransition(q1, 'a', q3);
    fa.addTransition(q1, 'b', q0);
    fa.addTransition(q2, 'a', q0);
    fa.addTransition(q2, 'b', q3);
    fa.addTransition(q3, 'a', q1);
    fa.addTransition(q3, 'b', q2);

    fa.addFinalState(q0);
    string input;
    cout << "Enter input string for FA5: ";
    cin >> input;
    cout << (fa.isAccepted(input) ? "Accepted" : "Not Accepted") << endl;
}

int main()
{
    int choice;
    cout << "Menu: ";
    // write all the FA'5 definiton
    cout << "\n1. FA1: Accepts strings with three consecutive 1's" << endl;
    cout << "2. FA2: Accepts strings with exactly two or three 1's (Interpretation 1: Not consecutive)" << endl;
    cout << "3. FA2: Accepts strings with exactly two or three 1's (Interpretation 2: consecutive)" << endl;
    cout << "4. FA3: Accepts strings of length 4 or more with the first two characters the same as the last two" << endl;
    cout << "5. FA4: Accepts strings where the language is a(a+b)*b" << endl;
    cout << "6. FA5: Accepts strings for EVEN-EVEN" << endl;
    cout << "Choose Finite Automaton to run (1-6): ";

    cin >> choice;

    switch (choice)
    {
    case 1:
        runFA1();
        break;
    case 2:
        runFA2();
        break;
    case 3:
        runFA3();
        break;
    case 4:
        runFA4();
        break;
    case 5:
        runFA5();
        break;
    case 6:
        runFA6();
        break;
    default:
        cout << "Invalid choice" << endl;
    }

    return 0;
}



unordered_set<int> combineSets(const unordered_set<int> &set1, const unordered_set<int> &set2)
{
    unordered_set<int> resultSet = set1;
    resultSet.insert(set2.begin(), set2.end());
    return resultSet;
}

int createStatePair(int state1, int state2, int numStates2)
{
    return state1 * numStates2 + state2;
}

FiniteAutomaton unionFA(const FiniteAutomaton &fa1, const FiniteAutomaton &fa2)
{
    FiniteAutomaton resultFA;
    int numStates2 = fa2.transitions.size();

    resultFA.setInitialState(createStatePair(fa1.initialState, fa2.initialState, numStates2));

    for (const auto &[state1, trans1] : fa1.transitions)
    {
        for (const auto &[state2, trans2] : fa2.transitions)
        {
            for (const auto &[input, nextState1] : trans1)
            {
                int nextState2 = trans2.at(input);
                resultFA.addTransition(createStatePair(state1, state2, numStates2), input, createStatePair(nextState1, nextState2, numStates2));
            }
        }
    }

    for (int finalState1 : fa1.finalStates)
    {
        for (int state2 = 0; state2 < numStates2; ++state2)
        {
            resultFA.addFinalState(createStatePair(finalState1, state2, numStates2));
        }
    }
    for (int finalState2 : fa2.finalStates)
    {
        for (int state1 = 0; state1 < fa1.transitions.size(); ++state1)
        {
            resultFA.addFinalState(createStatePair(state1, finalState2, numStates2));
        }
    }

    return resultFA;
}

FiniteAutomaton intersectionFA(const FiniteAutomaton &fa1, const FiniteAutomaton &fa2)
{
    FiniteAutomaton resultFA;
    int numStates2 = fa2.transitions.size();

    resultFA.setInitialState(createStatePair(fa1.initialState, fa2.initialState, numStates2));

    for (const auto &[state1, trans1] : fa1.transitions)
    {
        for (const auto &[state2, trans2] : fa2.transitions)
        {
            for (const auto &[input, nextState1] : trans1)
            {
                int nextState2 = trans2.at(input);
                resultFA.addTransition(createStatePair(state1, state2, numStates2), input, createStatePair(nextState1, nextState2, numStates2));
            }
        }
    }

    for (int finalState1 : fa1.finalStates)
    {
        for (int finalState2 : fa2.finalStates)
        {
            resultFA.addFinalState(createStatePair(finalState1, finalState2, numStates2));
        }
    }

    return resultFA;
}

FiniteAutomaton concatenateFA(const FiniteAutomaton &fa1, const FiniteAutomaton &fa2)
{
    FiniteAutomaton resultFA;
    int offset = fa1.transitions.size();

    resultFA.transitions = fa1.transitions;
    resultFA.setInitialState(fa1.initialState);
    resultFA.finalStates = fa2.finalStates;

    for (const auto &[state, trans] : fa2.transitions)
    {
        for (const auto &[input, nextState] : trans)
        {
            resultFA.addTransition(state + offset, input, nextState + offset);
        }
    }

    for (int finalState1 : fa1.finalStates)
    {
        resultFA.addTransition(finalState1, 'e', fa2.initialState + offset);
    }

    return resultFA;
}

FiniteAutomaton createFA1()
{
    FiniteAutomaton fa;
    const int q0 = 0, q1 = 1, q2 = 2;

    fa.setInitialState(q0);
    fa.addTransition(q0, 'a', q1);
    fa.addTransition(q1, 'a', q1);
    fa.addTransition(q1, 'b', q1);
    fa.addFinalState(q1);

    return fa;
}

FiniteAutomaton createFA2()
{
    FiniteAutomaton fa;
    const int q0 = 0, q1 = 1;

    fa.setInitialState(q0);
    fa.addTransition(q0, 'a', q0);
    fa.addTransition(q0, 'b', q1);
    fa.addTransition(q1, 'a', q0);
    fa.addTransition(q1, 'b', q1);
    fa.addFinalState(q1);

    return fa;
}
void testFA(const FiniteAutomaton &fa, const vector<string> &testCases)
{
    for (const string &testCase : testCases)
    {
        cout << "Input: " << testCase << " -> " << (fa.isAccepted(testCase) ? "Accepted" : "Rejected") << endl;
    }
}
int main()
{
    FiniteAutomaton fa1 = createFA1();
    FiniteAutomaton fa2 = createFA2();

    FiniteAutomaton unionResult = unionFA(fa1, fa2);
    FiniteAutomaton intersectionResult = intersectionFA(fa1, fa2);
    FiniteAutomaton concatenationResult = concatenateFA(fa1, fa2);
    unionResult.printTransitionTable();
    string input;
    cout << "Enter input string: ";
    cin >> input;

    cout << "Union FA: " << (unionResult.isAccepted(input) ? "Accepted" : "Not Accepted") << endl;
    cout << "Intersection FA: " << (intersectionResult.isAccepted(input) ? "Accepted" : "Not Accepted") << endl;
    cout << "Concatenation FA: " << (concatenationResult.isAccepted(input) ? "Accepted" : "Not Accepted") << endl;
    cout << "Testing Union FA:" << endl;
    vector<string> unionTestCases = {"a", "ab", "b", "ba", "aa", "aab", "bab", "", "bb", "baaa"};
    testFA(unionResult, unionTestCases);

    cout << "\nTesting Intersection FA:" << endl;
    vector<string> intersectionTestCases = {"ab", "aab", "aabb", "", "a", "b", "ba", "aa", "bb", "baaa"};
    testFA(intersectionResult, intersectionTestCases);
    cout << "\nTesting Concatenation FA:" << endl;
    vector<string> concatenationTestCases = {"ab", "aab", "aabb", "aaab", "", "a", "b", "ba", "aa", "bb"};
    testFA(concatenationResult, concatenationTestCases);
    return 0;
}
#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

class TuringMachine {
public:
    void addTransition(int fromState, char input, int toState, char write, char move) {
        transitions[fromState][input] = {toState, write, move};
    }

    string simulate(string input) {
        int currentState = 0;
        int head = 0;
        vector<char> tape(input.begin(), input.end());
        tape.push_back('_'); // End of tape

        while (currentState != -1) {
            char currentChar = tape[head];
            if (transitions[currentState].find(currentChar) == transitions[currentState].end()) {
                return "Not Accepted";
            }

            auto [nextState, writeChar, moveDir] = transitions[currentState][currentChar];
            tape[head] = writeChar;
            currentState = nextState;

            if (moveDir == 'R') {
                head++;
                if (head >= tape.size()) {
                    tape.push_back('_'); // Extend tape with blank if moving right beyond current size
                }
            } else if (moveDir == 'L') {
                head--;
                if (head < 0) {
                    tape.insert(tape.begin(), '_'); // Extend tape on the left with blank if moving left of start
                    head = 0;
                }
            }
        }

        return string(tape.begin(), tape.end());
    }

private:
    map<int, map<char, tuple<int, char, char>>> transitions;
};
void handleAnBnCn() {
    TuringMachine tm;

    // Transition to mark each 'a', 'b', 'c' with 'd' in sequence
    tm.addTransition(0, 'a', 1, 'd', 'R');   // Mark the first 'a' as 'd'
    tm.addTransition(1, 'a', 1, 'a', 'R');   // Move right over remaining 'a's
    tm.addTransition(1, 'd', 1, 'd', 'R');   // Move right over marked 'd's
    tm.addTransition(1, 'b', 2, 'd', 'R');   // Mark the first 'b' as 'd'
    tm.addTransition(2, 'b', 2, 'b', 'R');   // Move right over remaining 'b's
    tm.addTransition(2, 'd', 2, 'd', 'R');   // Move right over marked 'd's
    tm.addTransition(2, 'c', 3, 'd', 'L');   // Mark the first 'c' as 'd' and start moving left

    // Move left to the beginning of the tape to find the next 'a'
    tm.addTransition(3, 'b', 3, 'b', 'L');   // Move left over 'b's
    tm.addTransition(3, 'd', 3, 'd', 'L');   // Move left over 'd's
    tm.addTransition(3, 'a', 3, 'a', 'L');   // Move left over 'a's
    tm.addTransition(3, '_', 0, '_', 'R');   // When blank (start of tape) is reached, go to state 0

    // Final check: Accept if only 'd's and blanks remain
    tm.addTransition(0, 'd', 0, 'd', 'R');   // If all 'a's are marked, proceed to verification
    tm.addTransition(0, '_', -1, '_', 'R');  // Accept if only 'd's and blanks remain

    string input;
    cout << "Enter the string to be tested (a^n b^n c^n): ";
    cin >> input;

    string result = tm.simulate(input);
    if (result == "Not Accepted") {
        cout << "Not Accepted" << endl;
    } else {
        cout << "Accepted" << endl;
    }
}



void handleBinaryIncrement() {
    TuringMachine tm;

    // Define transitions for binary increment
    tm.addTransition(0, '0', 0, '0', 'R');
    tm.addTransition(0, '1', 0, '1', 'R');
    tm.addTransition(0, '_', 1, '_', 'L');
    tm.addTransition(1, '0', -1, '1', 'R');  // End the increment if we find a '0' to flip to '1'
    tm.addTransition(1, '1', 1, '0', 'L');   // Carry over if we find a '1' (flip to '0')
    tm.addTransition(1, '_', -1, '1', 'R');  // If all bits are '1', add '1' at the beginning

    string input;
    cout << "Enter the binary number to increment: ";
    cin >> input;

    string result = tm.simulate(input);
    if (result == "Not Accepted") {
        cout << "Not Accepted" << endl;
    } else {
        // Remove trailing blanks
        auto endPos = find(result.begin(), result.end(), '_');
        result.erase(endPos, result.end());
        cout << "Incremented Result: " << result << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "Menu:" << endl;
        cout << "1. Test a^n b^n c^n" << endl;
        cout << "2. Increment binary number" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                handleAnBnCn();
                break;
            case 2:
                handleBinaryIncrement();
                break;
            case 3:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
#include <iostream>
#include <stack>
#include <string>

using namespace std;

class PDA {
public:
    // Simulate PDA for {a^n b^n | n > 0}
    bool simulateAnBn(const string &input) {
        stack<char> st;
        int i = 0;

        // Push 'a's onto the stack
        while (i < input.length() && input[i] == 'a') {
            st.push('a');
            i++;
        }

        // Pop 'a's for each 'b' encountered
        while (i < input.length() && input[i] == 'b') {
            if (st.empty() || st.top() != 'a') return false;
            st.pop();
            i++;
        }

        // The input is valid if the stack is empty and all characters are processed
        return st.empty() && i == input.length();
    }

    // Simulate PDA for {w X w^r | w ∈ {a, b}*, X is a special symbol}
    bool simulateWXRWr(const string &input) {
        stack<char> st;
        int i = 0;

        // Push 'a' or 'b' onto the stack until 'X' is found
        while (i < input.length() && input[i] != 'X') {
            st.push(input[i]);
            i++;
        }

        // Check for presence of 'X'
        if (i == input.length() || input[i] != 'X') return false;
        i++;  // Move past 'X'

        // For each character after 'X', pop from the stack and check if it matches
        while (i < input.length()) {
            if (st.empty() || st.top() != input[i]) return false;
            st.pop();
            i++;
        }

        // The input is valid if the stack is empty and all characters are processed
        return st.empty();
    }

    // Menu to select and simulate each PDA
    void run() {
        int choice;
        string input;

        do {
            cout << "\nMenu:\n";
            cout << "1. Test language {a^n b^n | n > 0}\n";
            cout << "2. Test language {w X w^r | w ∈ {a, b}*}\n";
            cout << "3. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter the string to test (a^n b^n): ";
                    cin >> input;
                    if (simulateAnBn(input)) {
                        cout << "Accepted\n";
                    } else {
                        cout << "Not Accepted\n";
                    }
                    break;
                case 2:
                    cout << "Enter the string to test (w X w^r): ";
                    cin >> input;
                    if (simulateWXRWr(input)) {
                        cout << "Accepted\n";
                    } else {
                        cout << "Not Accepted\n";
                    }
                    break;
                case 3:
                    cout << "Exiting the program.\n";
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        } while (choice != 3);
    }
};

int main() {
    PDA pda;
    pda.run();
    return 0;
}
