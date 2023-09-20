typedef struct edge {
    int distance;
    struct graphNode *destination;
    struct edge *next;
} Edge;

typedef struct graphNode {
    char name[20];
    struct graphNode *next;
    struct edge *edges;
} GraphNode;

void DisplayMenu()
{
    printf("[1] Assign Names to Nodes\n");
    printf("[2] Starting Location\n");
    printf("[3] Destination\n");
    printf("[4] Shortest Distance\n");
    printf("[5] Exit\n");
}

int AskChoice()
{
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void AssignNames(GraphNode **head)
{
    GraphNode *newNode, *temp;
    for (int i = 1; i <= 5; i++) {
        newNode = (GraphNode*)malloc(sizeof(GraphNode));

        printf("Enter name of Node %d: ", i);
        scanf("%s", newNode->name);

        newNode->edges = NULL;
        newNode->next = NULL;
        
        if (*head == NULL) {
            *head = newNode;
        } else {
            temp = *head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

void DisplayNode(GraphNode *head)
{
    GraphNode *current = head;
    while(current)
    {
        puts(current->name);
        current = current->next;
    }
}

void AskStartingNode(char startNodeName[])
{
    printf("Starting Node Name: ");
    scanf("%s", startNodeName);
}

GraphNode *FindLocation(GraphNode *head, char startNodeName[])
{
    GraphNode *current = head;
    int status = 0;
    while(current)
    {
        if(strcmp(current->name, startNodeName) == 0)
        {
            status = 1;
           break;
        }
        current = current->next;
    }
    if(status == 0)
    {
        current = NULL;
        printf("Node is not found\n");
    }
    else{
        printf("%s\n", current->name);
    }

    return current;
}

void GraphOperations(GraphNode *head, Edge *edge)
{
    GraphNode *startingLocation = NULL;
    char startNodeName[20];
    int choice;

    do{
        DisplayMenu();
        choice = AskChoice();
        switch(choice)
        {
            case 1:
                  AssignNames(&head);
                  //DisplayNode(head);
                  break;
            case 2:
                  AskStartingNode(startNodeName);
                  startingLocation = FindLocation(head, startNodeName);
                  break; 
            default:
                  printf("\nPlease try Again\n");           

        }

    }while(choice != 5);
}
