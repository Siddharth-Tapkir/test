# #7. Chatbot
# Simple Rule-Based Chatbot with Tokenization

import random

# Chatbot responses
responses = {
    "hello": [
        "Hello! How can I help you?",
        "Hi! Nice to meet you!"
    ],

    "hi": [
        "Hi there!",
        "Hello!"
    ],

    "how": [
        "I am fine. How are you?",
        "I am doing great!"
    ],

    "name": [
        "I am a Python Chatbot."
    ],

    "what": [
        "I can answer simple questions and chat with you."
    ],

    "thank": [
        "You're welcome!",
        "Happy to help!"
    ],

    "bye": [
        "Goodbye!",
        "Have a nice day!"
    ]
}


# Starting message
print("Chatbot: Hello! I am your Python chatbot.")
print("Chatbot: Type 'bye' to exit.\n")


# Chat loop
while True:

    # Take user input
    user_input = input("You: ").lower().strip()

    # Tokenization
    tokens = user_input.split()

    # Display tokens
    print("Tokens:", tokens)

    # Exit condition
    if "bye" in tokens:
        print("Chatbot:", random.choice(responses["bye"]))
        break

    found = False

    # Check each token
    for token in tokens:

        if token in responses:

            print("Chatbot:", random.choice(responses[token]))

            found = True
            break

    # No matching keyword
    if not found:
        print("Chatbot: Sorry, I don't understand. Please ask something else.")