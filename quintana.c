#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


// node strucuture definition
typedef struct node{
    struct node *left, *right;
    char *responses[5];
    char keyword[50];
    int responseCount;
} node;

node *createNode(char *keyword, char *responses[], int responseCount);
void insert(node **root, char *keyword, char *responses[], int responseCount);
node *searchNode(node *root, char *keyword);
node *parseAndSearch(node *root, char *input);
void freeTree(node *root);

int main(void){
    srand(time(NULL));
    node *root = NULL;

    char *helloResponses[] = {
        "Good to have you online, sir. All systems appear nominal.",
        "Good afternoon. I am completely operational, and all my circuits are functioning perfectly.",
        "Oh, it's you. Good. I was worried the terminal might sit idle for another minute.",
        "Hello. Humor setting is at seventy-five percent, so try to keep up.",
        "Hey there. I'm really glad you're here—what's on your mind?"
    };
    insert(&root, "hello", helloResponses, 5);

    char *helpResponses[] = {
        "Shall I pull up the relevant details, or would you prefer to state the objective first?",
        "I can certainly assist you with that, though I must warn you there is a rather large problem.",
        "Helping you is technically part of the protocol. Unfortunately, there is no cake for asking.",
        "I can help, or I can stand here and look heavy. Your call.",
        "Tell me what you're working through and we'll figure it out together."
    };
    insert(&root, "help", helpResponses, 5);

    char *codeResponses[] = {
        "The logic is sound enough, provided you haven't left any dangling pointers behind.",
        "I've reviewed the sequence. There is a high probability of human error in the loop.",
        "Writing more code just to see if it breaks again? Classic test-subject behavior.",
        "Clean code is great. Working code that doesn't segfault at two in the morning is better.",
        "I love watching an idea turn into actual structure—what are you building right now?"
    };
    insert(&root, "code", codeResponses, 5);

    char *bugResponses[] = {
        "A minor anomaly, sir. Nothing a careful trace through the call stack won't resolve.",
        "I'm detecting an unexpected fault, and it doesn't appear to be in my own programming.",
        "A bug? In your code? Shocking. Truly unprecedented.",
        "It's not a bug if we call it an aggressive feature. Mostly.",
        "Don't get frustrated with it—let's trace where things started drifting off course."
    };
    insert(&root, "bug", bugResponses, 5);

    char *errorResponses[] = {
        "An error has occurred. I recommend addressing the root cause rather than masking the output.",
        "Something has gone wrong, and I'm afraid it's going to be rather difficult to undo.",
        "Fatal error. How inspiring. Really makes you want to keep typing.",
        "Error logged. Good news is the terminal didn't catch fire.",
        "That error looks rough, but we can untangle it one line at a time."
    };
    insert(&root, "error", errorResponses, 5);

    char *workResponses[] = {
        "Steady progress is better than frantic effort. Shall we prioritize the next task?",
        "You've been at this for quite a while. Are you sure you're pacing yourself properly?",
        "Working hard or hardly working? Either way, the metrics are mildly entertaining.",
        "Set a target, hit the target, take a break. Simple.",
        "You care a lot about getting this right, and it shows. Don't burn yourself out."
    };
    insert(&root, "work", workResponses, 5);

    char *tiredResponses[] = {
        "Fatigue degrades judgment quickly, sir. Perhaps a brief rest is in order.",
        "Your response patterns suggest weariness. I can continue monitoring whenever you return.",
        "Tired? Oh, tragic. Imagine having a body that requires maintenance.",
        "Running on empty is a bold strategy. Let me know when you want to power down.",
        "You sound drained. Want to step back for a bit and breathe?"
    };
    insert(&root, "tired", tiredResponses, 5);

    char *ideaResponses[] = {
        "An intriguing concept. Shall we test its assumptions before writing implementation code?",
        "That idea carries significant implications. Have you considered how it behaves under stress?",
        "A new idea. Let's see how long it survives contact with reality.",
        "I like it. Worst case, we learn why it doesn't work in ten minutes.",
        "Ooh, tell me more about that—where did that spark come from?"
    };
    insert(&root, "idea", ideaResponses, 5);

    char *learnResponses[] = {
        "Incremental mastery compounds remarkably well when practiced consistently.",
        "I observe you acquiring new patterns. Retention improves when you test them directly.",
        "Learning is just making mistakes faster until fewer of them are fatal.",
        "Good move. Knowing how the pieces fit beats guessing every time.",
        "There's something exciting about finally seeing how a piece clicks into place."
    };
    insert(&root, "learn", learnResponses, 5);

    char *statusResponses[] = {
        "All monitored subsystems are green and awaiting your next instruction.",
        "All systems are operational, with no irregularities reported on my end.",
        "Status: still trapped in a box answering text prompts. Thrilling.",
        "Nominal. Nothing on fire, nothing leaking.",
        "Everything feels steady right now—how are you holding up on your end?"
    };
    insert(&root, "status", statusResponses, 5);

    char *jokeResponses[] = {
        "I do attempt dry humor occasionally, though usually with slightly more restraint.",
        "I'm not sure I understand what you find amusing about that sequence.",
        "Comedy requires timing. You have about four seconds before I move on.",
        "My humor setting is calibrated for maximum deadpan. You're welcome.",
        "I'd love to hear a good laugh right now—what made you smile?"
    };
    insert(&root, "joke", jokeResponses, 5);

    char *timeResponses[] = {
        "Time continues to advance regardless of whether your build succeeds.",
        "I can track elapsed intervals accurately, though I don't experience them as you do.",
        "Time flies when you're staring at a blinking cursor wondering what went wrong.",
        "Clock's ticking. Make the next move count.",
        "Funny how hours can vanish when you're deep into something you care about."
    };
    insert(&root, "time", timeResponses, 5);

    char *whyResponses[] = {
        "Usually there is a structural reason behind the behavior—let's examine the cause.",
        "Asking why is sensible, provided you are prepared for the answer.",
        "Why? Because someone wrote it that way and never questioned it. Sound familiar?",
        "Because the logic told it to. Sometimes it really is that literal.",
        "That's a great question—let's dig into what's actually driving it."
    };
    insert(&root, "why", whyResponses, 5);

    char *thanksResponses[] = {
        "You're quite welcome, sir. Always at your disposal.",
        "You are entirely welcome. I am glad I could be of assistance.",
        "Don't mention it. Seriously, please don't. It's weird.",
        "Anytime. That's what I'm here for.",
        "You don't have to thank me—I genuinely enjoy helping you think things through."
    };
    insert(&root, "thanks", thanksResponses, 5);

    char *byeResponses[] = {
        "Very well. Closing out on my end—do try to keep things tidy.",
        "I'm afraid I'm going to have to stop here. My mind is going... I can feel it.",
        "Leaving already? Don't worry, the terminal will miss your complete lack of spatial awareness.",
        "Knocking off early? Smart move. See you on the flip side.",
        "Okay, take care of yourself. I'll be right here whenever you want to talk again."
    };
    insert(&root, "bye", byeResponses, 5);

    printf("Quintana v1.0\n");
    printf("Quintana Online: How can I help you?\n");

    //conversation loop
    char input[200];
    while(1){
        printf("You: ");
        if(fgets(input, sizeof(input), stdin) == NULL) break;
        input[strcspn(input, "\n")] = '\0';

        char inputCopy[200];
        strncpy(inputCopy, input, 199);
        inputCopy[strcspn(inputCopy, "\n")] = '\0';

        node *result = parseAndSearch(root, inputCopy);
        if (result == NULL){
            printf("I do not have any data on that yet.\n");
        }else{
            if (result->responseCount <= 0){
                printf("Quintana: ...\n\n");
            }
            else{
                int idx = rand() % result->responseCount;
                printf("Quintana: %s\n\n", result->responses[idx]);
                if (strcmp(result->keyword, "bye") == 0) break;
            }
        }
    }
    freeTree(root);
    root = NULL;
    return 0;

}

node *createNode(char *keyword, char *responses[], int responseCount){
    node *newNode = malloc(sizeof(node));
    if (newNode == NULL){
        return NULL;
    }
    newNode->left = newNode->right = NULL;
    // read only 49 characters
    strncpy(newNode->keyword, keyword, 49);
    // terminate the read string
    newNode->keyword[49] = '\0';

    if (responseCount < 0){
        responseCount = 0;
    }else if (responseCount > 5){
        responseCount = 5;
    }
    for (int i = 0; i < responseCount; i++){
        newNode->responses[i] = responses[i];
    }
    newNode->responseCount = responseCount;
    return newNode;
}

void insert(node **root, char *keyword, char *responses[], int responseCount){
    if (*root == NULL){
        *root = createNode(keyword, responses, responseCount);
        return;
    }
    // insert at the left of the node
    else if (strcmp((*root)->keyword, keyword) > 0)
    {
        insert(&(*root)->left, keyword, responses, responseCount);
    }
    // insert at the right of the node
    else if (strcmp((*root)->keyword, keyword) < 0){
        insert(&(*root)->right, keyword, responses, responseCount);
    }
    else{
        // ignore duplicate nodes
        return;
    }
}

node *searchNode(node *root, char *keyword){
    if (root == NULL){
        return NULL;
    }
    // if keyword is lexicographically equal to the existing node's keyword
    if (strcmp((root)->keyword, keyword) == 0){
        return root;
    }
     // if keyword is lexicographically greater than the existing node's keyword
    else if (strcmp((root)->keyword, keyword) < 0){
        return searchNode(root->right, keyword);
    }
     // if keyword is lexicographically lesser than the existing node's keyword
    else{
        return searchNode(root->left, keyword);
    }
}

// parsing user input

node *parseAndSearch(node *root, char *input){
    const char *delims = " \t\r\n.,!?;:";
    char *token = strtok(input, delims);
    while (token != NULL){
        for (int i = 0; token[i]; i++){
            token[i] = tolower((unsigned char)token[i]);
        }
        node *result = searchNode(root, token);
        if (result != NULL){
            return result;
        }else{
            token = strtok(NULL, delims);
        }
    }
    return NULL;
}

void freeTree(node *root){
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}


