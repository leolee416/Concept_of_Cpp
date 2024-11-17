# Assignment System

This is an introduction on how you use our assignment system for your _Concepts of C++ Programming_ lecture.
Get comfortable with the system as we will not only use it for the homework assignments, __but__ also for the __exam__!

## Requirements

- Docker is required for testing your code in the same environment that it will use for evaluation
- Git is used to receive and submit your solution - being fluent in the simple git workflow of `clone -> add -> commit -> push` is prerequisit (we recommend this [introdution](https://www.atlassian.com/git))

## Register a New User

Go to [https://cppprog.db.in.tum.de/concepts-of-cxx](https://cppprog.db.in.tum.de/concepts-of-cxx) and provide your LRZ id (e.g. `ge32jot`) as username, the corresponding password and an ssh public key.
In case you are not familiar with SSH and don't know how to generate and use SSH key pairs, this provides [a great introduction](https://docs.github.com/en/authentication/connecting-to-github-with-ssh/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent).
After you added your user and key, it might take up to one a few minutes for the changes to take affect.
After that you can verify that your public key was added by running `ssh git@cppprog.db.in.tum.de help`, as this provides you with a small overview of the available repositories on the git server and your permissions for them.

> You can register the same user mutliple times to add __different__ ssh keys for your user (up to five different keys)

## Doing your Homework

### Clone the assignment repository

First, you have to clone the repository for the respective assignment by running `git clone git@cppprog.db.in.tum.de:assignments/<your username>/a00`.
Using the same username, that you provided during registration, will create a folder `a00` in your current directory (exchange `a00` for later assignments).
The folder contains a starting point for your solution.

### Testing Locally

As the solution evaluation on our test servers might not finish before the deadline, it is __important__ that you test your solution locally beforehand.
For that matter, we provide a dockerfile that sets up the exact same environment that we use for testing.
Build the docker image that comes with the assignment template with `docker build . -t cppprog`.
Next, you can execute `docker run --rm -v $PWD/:/homework cppprog /homework/assessment.sh` inside your homework folder to run the evaluation in the exact same environment as we do during evalution.

> Get familiar with developing it that environment, as we will use the same setup for the exam as well

### Upload Solution

Once you finished your solution, add the required files to your git tracking and commit the changes.
Push your master branch, as only this one counts for the evaluation, using `git push` to upload your changes to the server.
If you hand in your solution after the respective deadline expired (or before we open the assignment), you will get a message upon pushing and the command will fail.
You can repeat this within the deadline for other commits, if you later want to provide fixes for your solution.
Only upload your source code and the cmake setup, refrain from uploading any binaries or build directories!

> Don't panick if your upload itself does not go through in time... Once you push your solution, we immediatly store the provided git hash (you will see a _"HASH UPDATED"_ in your commandline). If the upload of the rest of your data now fails or takes longer than expected, you can retry the upload via git push even after the deadline as long as the git hash didn't change!

### Get your Points / Look into the Logs

After you handed in your solution, it will be enqued and eventually evaluation with our test runner. Once your solution was tested (expect a delay of up to a week), we will upload the received points and respective logs to our database. You can check your received points with the `ssh git@cppprog.db.in.tum.de points` command and look into the logs using `ssh git@cppprog.db.in.tum.de logs a00`.

