# SSVIP-C-Plus-Plus-Programming-04
#FLOW CHART FOR Online Voting System
Start of the program.
Initialize variables: candidates, voters, and nextCandidateId.
Enter an infinite loop for the main menu:
a. Display the main menu options.
b. Prompt the user to enter their choice.
c. Based on the user's choice, execute one of the following actions:
Case 1: Register as a voter
Prompt for a username and password.
Register the voter.
Case 2: Register a candidate
Prompt for a candidate's name.
Register the candidate.
Case 3: Authenticate as a voter
Prompt for a username and password.
Check if the authentication is successful.
Case 4: Cast Vote
Check if there are registered voters.
Prompt for a username.
Check if the username is valid.
If valid, display the list of candidates and prompt for a candidate ID.
Check if the vote is valid, and if the voter has already voted.
Cast the vote and update the voter's status.
Case 5: View Candidates
Display the list of candidates.
Case 6: Exit
Exit the program.
Default: Invalid choice.
d. Repeat the loop.
