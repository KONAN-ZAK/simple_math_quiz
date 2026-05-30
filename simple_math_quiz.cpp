#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Quiz difficulty levels
enum enLevel { easy = 1, mid, hard, mixLevel };

// Quiz operation types
enum enOperation { add = 1, sub, multi, divi, mixOperation };

// Maximum number of questions allowed
const unsigned short maxQuestionsNumber = 10;

// Store a single question information
struct stQuestion {
	short number1, number2, correctAnswear, userAnswear;
	char operater;
	bool answearStatus = false;
};

// Store all quiz information
struct stQuiz {
	stQuestion QuestionsArr[::maxQuestionsNumber];
	unsigned short questionNumber;
	enLevel level;
	enOperation operation;
	unsigned short trueAnswears = 0;
	unsigned short wrongAnswears = 0;
	string passFail;
};

//_____________________general______________________________

// Generate random number between from and to
short getRandomNumber(short from, short to) {
	return rand() % (to - from + 1) + from;
}

// Create tab spacing
string Tab(short number) {
	string tab = "";

	for (int i = 1; i <= number; i++)
	{
		tab += "\t";
	}

	return tab;
}

// Change screen color depending on answer status
void playScreenAction(bool status) {
	// Green screen for correct answer
	if (status)
	{
		system("color 2F");
	}
	// Red screen for wrong answer
	else {
		system("color 4F");
	}
}

// Print final game over screen
void printGameOverMessage(string passFail) {
	cout << "\n\n\n" << Tab(3)
		<< "__________________________________________________________________________________________\n\n";
	cout << Tab(7) << "+ + +  G A M E   O V E R  + + + \n\n";
	cout << Tab(3) << "__________________________________________________________________________________________\n\n";
	cout << Tab(3) << "_____________________________________ Quizz Results: " << passFail << " _______________________________\n\n\n";
}

//________________________6________________________________

// Convert level enum to text
string GetQuestionLevelText(enLevel QuestionLevel) {
	string arrQuestionLevelText[4] =
	{ "Easy","Medium","Hard","Mixed" };
	return arrQuestionLevelText[QuestionLevel - 1];
}

// Convert operation enum to text
string GetQuestionTypeText(enOperation QuestionType) {
	string arrQuestionLevelText[5] =
	{ "Add","Subtraction","Multibliction","Division","Mixed" };
	return arrQuestionLevelText[QuestionType - 1];
}

// Print final quiz results
void playFinalResults(stQuiz quizz) {
	printGameOverMessage(quizz.passFail);

	cout << Tab(3) << "Number of Questions        : " << quizz.questionNumber << endl;
	cout << Tab(3) << "Questions operations Type  : " << GetQuestionTypeText(quizz.operation) << endl;
	cout << Tab(3) << "Questons difficulty Level  : " << GetQuestionLevelText(quizz.level) << endl;
	cout << Tab(3) << "Correct Answears           :" << quizz.trueAnswears << endl;
	cout << Tab(3) << "Wrong Answears             :" << quizz.wrongAnswears << endl;
	cout << Tab(3) << "__________________________________________________________________________________________\n\n";
}

//_______________________5_________________________________

// Decide if player passed or failed
string getpassFailedStatus(short trueAnswears, short wrongAnswears) {
	if (trueAnswears > wrongAnswears)
	{
		playScreenAction(true);
		return "PASSED :)";
	}
	else if (trueAnswears <= wrongAnswears) {
		playScreenAction(false);
		return "FAILED :(";
	}
}

//______________________4__________________________________

// Check if user answer is correct
bool isCorrect(short userAnswear, short correctAnswear) {
	return (userAnswear == correctAnswear);
}

// Print answer result and update status
void playResult(stQuestion& question) {
	if (isCorrect(question.userAnswear, question.correctAnswear)) {
		cout << "CORRECT :) " << endl;
		question.answearStatus = true;
		playScreenAction(true);
	}
	else
	{
		cout << "WRONG :( " << endl;
		cout << "correct answear is: " << question.correctAnswear << endl;
		question.answearStatus = false;
		playScreenAction(false);
	}
}

// Display question card and take user answer
void playCard(stQuestion& question) {
	cout << question.number1 << endl;
	cout << question.number2 << Tab(1);
	cout << question.operater << endl;
	cout << "_______________" << endl;

	cin >> question.userAnswear;
}

// Run all quiz questions
void runQuiz(stQuiz& quizz) {
	for (int q = 0; q < quizz.questionNumber; q++)
	{
		cout << "\n\nQUESTION [" << q + 1 << "/" << quizz.questionNumber << "]\n\n";

		playCard(quizz.QuestionsArr[q]);

		playResult(quizz.QuestionsArr[q]);

		// Count correct and wrong answers
		if (quizz.QuestionsArr[q].answearStatus == true)
		{
			quizz.trueAnswears++;
		}
		else
		{
			quizz.wrongAnswears++;
		}
	}
}

//_______________________3_________________________________

// Simple calculator function
short simpleCalculator(short number1,
	short number2,
	char operater) {
	switch (operater) {
	case '+':
		return(number1 + number2);

	case '-':
		return(number1 - number2);

	case '*':
		return(number1 * number2);

	case '/':
		return(number1 / number2);

	default:
		cout << "error";
		return 0;
	}
}

// Convert operation enum into symbol
char getOperaterSign(enOperation operation) {
	// Generate random operation if mixed selected
	if (operation == enOperation::mixOperation)
	{
		operation =
			enOperation(getRandomNumber(1, 4));
	}

	switch (operation) {
	case enOperation::add:
		return '+';

	case enOperation::sub:
		return '-';

	case enOperation::multi:
		return '*';

	case enOperation::divi:
		return '/';

	default:
		cout << "error";
		return 0;
	}
}

// Generate numbers based on difficulty level
short getNumber(enLevel level) {
	// Generate random level if mixed selected
	if (level == enLevel::mixLevel)
	{
		level = enLevel(getRandomNumber(1, 3));
	}

	switch (level) {
	case enLevel::easy:
		return getRandomNumber(1, 10);

	case enLevel::mid:
		return getRandomNumber(11, 100);

	case enLevel::hard:
		return getRandomNumber(101, 1000);

	default:
		cout << "error";
		return 0;
	}
}

// Fill one question information
stQuestion fillRequirment(enLevel level, enOperation operation) {
	stQuestion question;

	question.number1 = getNumber(level);

	question.number2 = getNumber(level);

	question.operater = getOperaterSign(operation);

	question.correctAnswear = simpleCalculator(question.number1, question.number2, question.operater);

	return question;
}

// Prepare all quiz questions
void prepareQuizQuestions(stQuiz& quizz) {
	for (int q = 0; q < quizz.questionNumber; q++)
	{
		quizz.QuestionsArr[q] = fillRequirment(quizz.level, quizz.operation);
	}
}

//______________________2__________________________________

// Get quiz operation from user
enOperation getQuizOperation(void) {
	unsigned short input;

	do {
		cout << "Enter Questions Operation [1]add [2]sub [3]multi [4]div [5]mix :";

		cin >> input;
	} while (input < 1 || input > 5);

	return enOperation(input);
}

// Get quiz difficulty level from user
enLevel getQuizLevel(void) {
	unsigned short input;

	do {
		cout << "Enter Questions Level [1]easy [2]mid [3]hard [4]mix :";

		cin >> input;
	} while (input < 1 || input > 4);

	return enLevel(input);
}

// Ask user for number of questions
short howManyQuestions(void) {
	short input;

	do
	{
		cout << "How many Questions Do you want to answear from 1 to 10 ?";

		cin >> input;
	} while (input < 1 || input > ::maxQuestionsNumber);

	return input;
}

// Initialize quizz settings
stQuiz initiateQuiz(void) {
	stQuiz quizz;

	quizz.questionNumber = howManyQuestions();

	quizz.level = getQuizLevel();

	quizz.operation = getQuizOperation();

	prepareQuizQuestions(quizz);

	return quizz;
}

//_____________________1___________________________________

// Ask player if they want to play again
bool StartGameAgain(void) {
	char input;

	do {
		cout << Tab(3)
			<< "Do you want to play agin? (Y , N): ";

		cin >> input;

		if (input == 'Y' || input == 'y')
		{
			return true;
		}
	} while (input != 'N' && input != 'n');

	return false;
}

// Reset console screen and color
void resetScreen(void) {
	system("cls");

	system("color 0F");
}

// Main quizz loop
void startQuiz(void) {
	stQuiz quizz;

	do
	{
		resetScreen();

		quizz = initiateQuiz();

		runQuiz(quizz);

		quizz.passFail = getpassFailedStatus(quizz.trueAnswears, quizz.wrongAnswears);

		playFinalResults(quizz);
	} while (StartGameAgain());
}

//____________________main________________________________

int main() {
	// Seed random generator
	srand((unsigned)time(NULL));

	startQuiz();

	return 0;
}