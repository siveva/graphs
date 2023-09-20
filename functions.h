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

void SetEdges(GraphNode *head)
{
    GraphNode *node1 = head;
    GraphNode *node2 = node1->next;
    GraphNode *node3 = node2->next;
    GraphNode *node4 = node3->next;
    GraphNode *node5 = node4->next;

    Edge *edge = (Edge*)malloc(sizeof(Edge));
    edge->destination = node2;
    edge->distance = 4;
    edge->next = node1->edges;
    node1->edges = edge;

    Edge *edge2 = (Edge*)malloc(sizeof(Edge));
    edge2->destination = node3;
    edge2->distance = 3;
    edge2->next = node2->edges;
    node2->edges = edge2;

    Edge *edge3 = (Edge*)malloc(sizeof(Edge));
    edge3->destination = node4;
    edge3->distance = 5;
    edge3->next = node2->edges;
    node2->edges = edge3;

    Edge *edge4 = (Edge*)malloc(sizeof(Edge));
    edge4->destination = node5;
    edge4->distance = 3;
    edge4->next = node3->edges;
    node3->edges = edge4;

    Edge *edge5 = (Edge*)malloc(sizeof(Edge));
    edge5->destination = node3;
    edge5->distance = 2;
    edge5->next = node4->edges;
    node4->edges = edge5;

    Edge *edge6 = (Edge*)malloc(sizeof(Edge));
    edge6->destination = node5;
    edge6->distance = 4;
    edge6->next = node4->edges;
    node4->edges = edge6;
    
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

void DisplayEdges(GraphNode *head)
{
    GraphNode *current = head;
    while(current)
    {
        Edge *edge = current->edges;
        while(edge)
        {
            printf("From %s to %s, distance = %d\n", current->name, edge->destination->name, edge->distance);
            edge = edge->next;
        }
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
                  SetEdges(head);
                  DisplayEdges(head);
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
