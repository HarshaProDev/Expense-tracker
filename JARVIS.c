//MINI JARVIS BUILD
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Speak function
void speak(char text[])
{
char command[500];

sprintf(command,
    "PowerShell -Command \"Add-Type -AssemblyName System.Speech; "
    "$speak = New-Object System.Speech.Synthesis.SpeechSynthesizer; "
    "$speak.Speak(\\\"%s\\\");\"",
    text);

system(command);

}
// Get voice command from Python
    void getVoiceInput(char input[])
{
system("python listen.py");

FILE *file = fopen("command.txt", "r");

if(file != NULL)
{
    if(fgets(input, 100, file) == NULL)
    {
        input[0] = '\0';
    }

    fclose(file);
}
else
{
    input[0] = '\0';
}

input[strcspn(input, "\n")] = 0;

}



int main()
{
    char You[100];
    printf("\nBot: Welcome master! Press exit to quit\n You:");
    speak("Welcome master! how is your day?");
 while(1)
 {
    memset(You, 0, sizeof(You));
    getVoiceInput(You);
    if(strlen(You) == 0)
    {
        continue;
    }

    printf("You said: %s\n", You);

    You[strcspn(You,"\n")]=0;
    for(int i=0;You[i]!='\0';i++)
    {
        if(You[i] >= 'A' && You[i] <= 'Z')
        {
            You[i]=You[i]+32;
        }
    }

    if(strcmp(You,"exit")==0)
    {
        printf("Bot: Thank you for time");
        speak("Goodbye master");
        break;
    }
    else if(strstr(You,"hey jarvis")!=NULL)
    {
        printf("Bot: Yes master!\n");
        speak("Yes master");
    }
    else if(strcmp(You,"hi")==0)
    {
        printf("Bot: hello master. what can i do for you\n You:");
        speak("Hello master. What can I do for you?");
    }
    else if(strstr(You,"what is your name?")!=NULL)
    {
        printf("Bot: I'm JARVIS\n You:");
        speak("I am Jarvis");
    }
    else if(strstr(You,"how are you?")!=NULL)
    {
        printf("Bot: I'm fine. what about you?\n You:");
        speak("yeah good what about you?");
    }
    else if(strstr(You,"i love you")!=NULL)
    {
        printf("Bot: Sorry! i'm just an intelligence so i cant love you back. But, I can help always\n You:");
        speak("Sorry i cant");
    }
    else if(strstr(You,"open chrome")!=NULL)
    {
        printf("opening chrome....\n You:");
        speak("Opening Chrome");
        system("start chrome");
    }
    else if(strstr(You,"open notepad")!=NULL)
    {
        printf("Bot: Opening notepad....\n You:");
        speak("Opening Notepad");
        system("start notepad");
    }
    else if(strstr(You, "youtube") != NULL) 
    { 
        printf("Bot: Opening YouTube...\n You:"); 
        speak("Opening YouTube");
        system("start https://www.youtube.com"); 
    }
    else if(strstr(You, "date") != NULL) 
    { 
        printf("Bot: Here is today's date:\n You:"); 
        speak("Here is today's date");
        system("date /t"); 
    }
    else if(strstr(You, "open google") != NULL) 
    { 
        printf("Bot: Opening google....\n You:"); 
        speak("yes master opening google");
        system("start https://www.google.com"); 
    }
    else
    {
        printf("Bot: Sorry! I'm still in learning stage\n You:");
        speak("I'm sorry");
    }
 }
}