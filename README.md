# Concept_of_Cpp
## src
- Find original assignments under folder `/Assignment`
- Find solution for assignments under folder `/Solution`

## Requirements

- Docker is required for testing your code in the same environment that it will use for evaluation
- Git is used to receive and submit your solution - being fluent in the simple git workflow of `clone -> add -> commit -> push` is prerequisit (we recommend this [introdution](https://www.atlassian.com/git))
- Highly recommand that used __Linux__ to do your homework and run test
- (For windows user) GitBash is used to run the test.

## Doing your Homework

### Testing Locally(Linux)

As the solution evaluation on our test servers might not finish before the deadline, it is __important__ that you test your solution locally beforehand.

For that matter, we provide a dockerfile that sets up the exact same environment that we use for testing.
Build the docker image that comes with the assignment template with `docker build . -t cppprog`.
Next, you can execute `docker run --rm -v $PWD/:/homework cppprog /homework/assessment.sh` inside your homework folder to run the evaluation in the exact same environment as we do during evalution.

### Testing Locally(Windows)

Build the docker image that comes with the assignment template with `docker build . -t cppprog`.
Before you excute 'docker run', excute `dos2unix assignment.sh` under `/path_to_workspace`. and run `dos2unix eval.sh` under `/path_to_your_workspace/your_task` if you want to evaluate your tasks. it is __neccessary__ that you work in windows environment.

Next, you can execute `docker run --rm -v $PWD/:/homework cppprog /homework/assessment.sh` in GitBash inside your homework folder to run the evaluation in the exact same environment as we do during evalution

> Get familiar with developing it that environment, as we will use the same setup for the exam as well
