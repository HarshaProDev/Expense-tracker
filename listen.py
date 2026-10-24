import speech_recognition as sr

r = sr.Recognizer()

try:
    with sr.Microphone() as source:
        print("Listening...")
        audio = r.listen(source)
        text = r.recognize_google(audio)

    print("You said:", text)

    with open("command.txt", "w") as file:
        file.write(text)

except Exception as e:
    print("ERROR:", e)

    with open("command.txt", "w") as file:
        file.write("")