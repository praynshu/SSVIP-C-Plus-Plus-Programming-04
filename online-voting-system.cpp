#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// Define a structure for a candidate
struct Candidate {
    int id;
    string name;
    int votes;
};

// Define a structure for a voter
struct Voter {
    string username;
    string password;
    bool hasVoted;
};

// Function to display the list of candidates
void displayCandidates(const vector<Candidate>& candidates) {
    cout << "List of Candidates:" << endl;
    for (const Candidate& candidate : candidates) {
        cout << candidate.id << ". " << candidate.name << " (" << candidate.votes << " votes)" << endl;
    }
}

// Function to register a new candidate
void registerCandidate(vector<Candidate>& candidates, int& nextCandidateId) {
    string name;
    cout << "Enter the candidate's name: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, name);
    candidates.push_back({nextCandidateId++, name, 0});
    cout << "Candidate registered successfully!" << endl;
}

// Function to register a new voter
void registerVoter(map<string, Voter>& voters) {
    string username, password;
    cout << "Enter a username: ";
    cin >> username;
    cout << "Enter a password: ";
    cin >> password;
    voters[username] = {username, password, false};
    cout << "Voter registered successfully!" << endl;
}

// Function to authenticate a voter
bool authenticateVoter(map<string, Voter>& voters, string& username, string& password) {
    if (voters.find(username) != voters.end() && voters[username].password == password) {
        return true;
    }
    return false;
}

// Function to cast a vote
void castVote(vector<Candidate>& candidates, map<string, Voter>& voters, string& username) {
    for (Candidate& candidate : candidates) {
        cout << candidate.id << ". " << candidate.name << endl;
    }

    int candidateId;
    cout << "Enter the candidate ID you want to vote for: ";
    cin >> candidateId;

    if (candidateId < 1 || candidateId > candidates.size()) {
        cout << "Invalid candidate ID. Vote not cast." << endl;
        return;
    }

    if (voters[username].hasVoted) {
        cout << "You have already voted. Cannot vote again." << endl;
        return;
    }

    candidates[candidateId - 1].votes++;
    voters[username].hasVoted = true;
    cout << "Vote cast successfully!" << endl;
}

int main() {
    vector<Candidate> candidates;
    map<string, Voter> voters;
    int nextCandidateId = 1;

    int choice;
    string username, password;

    while (true) {
        cout << "\nOnline Voting System" << endl;
        cout << "1. Register as a voter" << endl;
        cout << "2. Register a candidate" << endl;
        cout << "3. Authenticate as a voter" << endl;
        cout << "4. Cast Vote" << endl;
        cout << "5. View Candidates" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerVoter(voters);
                break;
            case 2:
                registerCandidate(candidates, nextCandidateId);
                break;
            case 3:
                cout << "Enter your username: ";
                cin >> username;
                cout << "Enter your password: ";
                cin >> password;
                if (authenticateVoter(voters, username, password)) {
                    cout << "Authentication successful!" << endl;
                } else {
                    cout << "Authentication failed. Invalid username or password." << endl;
                }
                break;
            case 4:
                if (voters.empty()) {
                    cout << "No registered voters. Register as a voter first." << endl;
                } else {
                    cout << "Enter your username: ";
                    cin >> username;
                    if (voters.find(username) == voters.end()) {
                        cout << "Invalid username. Register as a voter first." << endl;
                    } else {
                        castVote(candidates, voters, username);
                    }
                }
                break;
            case 5:
                displayCandidates(candidates);
                break;
            case 6:
                cout << "Exiting the voting system." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
