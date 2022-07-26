# Introduction to Visual Studio Code and C++

> Authors: Victor Hill and Joshua Candelaria (special thanks to Professor Neftali Watkinson and Professor Kris Miller)

Welcome to CS010B! In this lab, we will be configuring and introducing the basics of Visual Studio Code, an IDE with many useful features from syntax highlighting to intelligent code completion. In this introductory module, you will learn:

* How to install and configure VSCode for C++ programming
* How to compile with g++, a C++ compiler
* Basic use of VSCode with SSH

**IMPORTANT**: Before we proceed, make sure that you have a CS account. If you **don't have one/aren't sure if you have one**, [go to this link](https://sites.google.com/a/ucr.edu/cse-instructional-support/home/accounts#h.r2x4rti8gpg9) to set one up. The same site will help if you **forgot your password and need to reset it**.

## What is an IDE?

An IDE, or an integrated development environment, is a piece of software that provides us with a multitude of different components in one user interface to maximize productivity. The most common features in an IDE are a code/text editor (usually with syntax highlighting), build automation (a compiler, version control like Git, or automated testing), and a debugger. While IDEs are not required (you have written and compiled code without one before), they provide the tools to create bigger projects, collaborate with others, and make development more convenient.

## Why VSCode?

VSCode is an incredibly popular IDE ([the most popular in the world, actually!](https://insights.stackoverflow.com/survey/2021)), and for good reason. We chose it for this class because it is very lightweight and widely supports most langauges and features that are considered essential for development. It also has a large marketplace of extensions that make it easy to extend and personalize your version of VSCode. This doesn't mean that VSCode is the **best** IDE out there; we encourage you to get experience with other IDEs if you wish/if you are ever required to use a different one. Here are some general questions that you should ask yourself for finding an IDE that suits your needs:

* Does the IDE support the programming languages I am going to use? (Bonus: is it recommended by the development community as a good option for those languages)
* Is it mature and well supported?
* Does it support collaboration and a direct connection to a respository?
* Does it support other technology I will use for my project? (connecting to servers, alternative testing frameworks, etc.)
* Does it have code autocomplete?
* Does it work with my operating system?
* Do I have to pay a license for it?
* Can I customize it however I want?

## Part 1: Installation and Configuration

First, install the correct version of VSCode at [this link](https://code.visualstudio.com/download) for your operating system and processor. Once VSCode is installed, we need to install an extension called Remote-SSH. This extension will allow you to work on UCR's servers remotely, saving your progress across devices and allowing you to use the software already installed on the server (like the compiler). To do this, open VSCode go to the extension tab on the left bar, and search for Remote-SSH. Make sure it is the extension that is published by Microsoft, verified with the blue check.

<p align="center">
    <img src="images/installremotessh.gif" alt="Installing Remote-SSH Extension">
</p>

Now, we can SSH into UCR servers! To set up a connection to CS010B servers, follow these steps:

1. Open the command palette (press F1), and type "Remote-SSH". Select the "Remote-SSH: Connect to Host" option.
2. Click add a new host, and type the following command. Note that your CS username is the same as your UCR NetID.

    ``` ssh [your_cs_username]@cs010b.cs.ucr.edu ```
   
3. Now you have saved the address as a known host. Repeat step 1, and this time you will be asked for your password in a new instance of VSCode.
4. Now that you're connected, go to the extensions marketplace and install the C++ extension. It should look like this:

<p align="center">
    <img src="images/cppextension.png" alt="C++ Extension">
</p>

Now, you have a fully configured workspace on VSCode while connected to school servers!

In order to close the connection, click the bottom left corner (it should say `SSH: cs010b.cs.ucr.edu`). It should pull up the command palette, and to exit, press "Close remote connection". **PLEASE DON'T FORGET TO DO THIS WHENEVER YOU ARE DONE!** Closing out of VSCode without manually closing the connection doesn't log you out on the server, which consumes precious server resources.

## Working on a Remote Server

Open a folder using Ctrl+O / Cmd+O, or by pressing the first icon on the tab on the left (called the explorer). This should default to your home directory/folder, which should have the path `/home/csmajs/[your_cs_username]` for students in CS related majors or `/class/classes/[your_cs_username]` for students who are taking CS 010B as a service course for their major.  (you may be asked for your password again). This will be the directory that all your files will be in; think of it as your reserved space on the UCR server.

In order to demonstrate how to use VSCode with C++ so you can do your labs, we will write and compile a simple program. Create a new file called `main.cpp`, and copy in the following code:

```cpp
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input;
    cout << "What's your name?" << endl;
    getline(cin, input);
    cout << "Hello " << input << '!' << endl;
}
```

Now that you have your source code, lets compile it! Open up a terminal by using the shortcut `Ctrl + ~` or `Cmd + ~` if you're on Mac. Now, type in and run the following command:

``` g++ main.cpp ```

Let's break down what this command is: `g++` is the compiler that we use for C++ source code. `main.cpp` is simply the target source code file we want to compile.

> Note: The shell that we are using is called Bash. A useful feature of a lot of shells is that they support autocomplete. For example, you can type ```g++ m``` and press the Tab key, and it will autocomplete the name to ```main.cpp```. This will be useful for when you have longer file names.

Now, if your program has no errors and compiles, there should be no input in your console, and just be awaiting your next input. If your program wasn't able to compile, you would see all your error messages here. You should see that there's a new file in your directory called `a.out`. This is your executable! In order to run it, type and run this following command.

``` ./a.out ```

The `./` followed by the name of the exectuable is the way we run our compiled programs.

The terminal should now be running your executable, and waiting for your input.

By default, source files compiled by g++ are named ```a```, but usually we want to give our programs recognizable names. To do this, we can use the compiler flag ```-o```, which is a compiler flag that names the output executable. First, delete the `a.out` file. Then, run the following command:

``` g++ -o hello_world main.cpp ```

This will compile ```main.cpp``` into an executable called ```hello_world```, and you can run it by running the command ```./hello_world``` in your console.

## Optional: Useful Features of VSCode

VSCode has many useful features that help increase your productivity. You will learn more about some of these features later (debugging, how to use your terminal, and other features when editing multiple files at once), but some of the editing features that will be useful to you right now are:

| ![Multiple Cursors](images/multiplecursor.gif) | ![Rename Variables](images/renamevariable.gif) | ![Go to Definition](images/gotodefinition.gif)
| :--: | :--: | :--: |
| *Alt + Left Click to add a cursor*| *Rename variables/functions easily and quickly*| *Go to definition/declaration of a variable/function* 

| ![Highlight and Comment](images/highlightandcomment.gif)| ![Move Line](images/moveline.gif)|
| :--: | :--: |
| *Highlight line by line with Ctrl + L or Cmd + L, then comment with Ctrl+/ or Cmd+/* | *Move a line of code with Alt + Arrow Keys* |

Another useful setting is in File > Auto Save, to prevent yourself from potentially losing progress.

To find even more useful commands, press F1 to bring up the Command Palette that allows you to search for whatever command you need. [Here](https://code.visualstudio.com/docs/getstarted/keybindings) is a list of keybindings if you wish to get familiar with the many shortcuts in VSCode.

We encourage you to become more familiar and comfortable with your new development environment. Make it your own! Install a theme, use some fun extensions, and play around in C++. You can create your own keybinds and themes, and add your own extensions from the marketplace. Later in this course, we will go over some more useful features that you will be able to use in future courses and beyond.
