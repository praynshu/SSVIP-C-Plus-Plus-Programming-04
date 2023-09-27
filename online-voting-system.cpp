#include <iostream>
#include <vector>

using namespace std;

// Define a structure for a candidate
struct Candidate {
    int id;
    string name;
    int votes;
};

// Function to display the list of candidates
void displayCandidates(const vector<Candidate>& candidates) {
    cout << "List of Candidates:" << endl;
    for (const Candidate& candidate : candidates) {
        cout << candidate.id << ". " << candidate.name << " (" << candidate.votes << " votes)" << endl;
    }
}

// Function to cast a vote
void castVote(vector<Candidate>& candidates, int candidateId) {
    for (Candidate& candidate : candidates) {
        if (candidate.id == candidateId) {
            candidate.votes++;
            cout << "Vote cast successfully!" << endl;
            return;
        }
    }
    cout << "Invalid candidate ID. Vote not cast." << endl;
}

int main() {
    vector<Candidate> candidates;
    candidates.push_back({1, "Candidate A", 0});
    candidates.push_back({2, "Candidate B", 0});
    candidates.push_back({3, "Candidate C", 0});

    int choice;
    while (true) {
        cout << "\nOnline Voting System" << endl;
        cout << "1. View Candidates" << endl;
        cout << "2. Cast Vote" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayCandidates(candidates);
                break;
            case 2: {
                int candidateId;
                cout << "Enter the candidate ID you want to vote for: ";
                cin >> candidateId;
                castVote(candidates, candidateId);
                break;
            }
            case 3:
                cout << "Exiting the voting system." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
