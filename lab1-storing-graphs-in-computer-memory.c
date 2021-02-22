#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct adjNode {
  int vertex;
  struct adjNode* next;
};
struct adjNode* createNodeForAdjList(int);

struct adjList {
  int numVertices;
  struct adjNode** adjLists;
};

struct adjList* createAdjList();

void addEdgeForAdjList(struct adjList* graph, int s, int d);

void freeAdjList(struct adjList*);

int vertices = 0;
int edges = 0;
struct adjList* adjListGraph = NULL;

short* inputIncidenceMatrix();

void editIncidenceMatrix(short *matrix);

short* inputAdjacencyMatrix();

void editAdjacencyMatrix(short* adjMatrix);

struct adjList* inputAdjacencyList();

void editAdjacencyList(struct adjList* graph);

int getVerticesAmount();

int getEdgesAmount();

_Bool isIncMatrixDirected(short* incMatrix);

struct adjList* convertFromIncidenceMatrixToAdjList(short* matrix);

void convertFromUndirectedIncidenceMatrixToAdjList(short* incMatrix, struct adjList* resultList);

void convertFromDirectedIncidenceMatrixToAdjList(short* incMatrix, struct adjList* resultList);

struct adjList* convertFromAdjMatrixToAdjList(short* matrix);

_Bool isAdjMatrixDirected(short *adjMatrix);

struct adjList* convertFromDirectedAdjMatrixToAdjList(short *adjMatrix);

struct adjList* convertFromUndirectedAdjMatrixToAdjList(short *adjMatrix);

short* convertFromAdjListToIncidenceMatrix();

short* convertFromAdjListToUndirectedIncidenceMatrix();

short* convertFromAdjListToDirectedIncidenceMatrix();

_Bool isIncMatrixDirectedCheckByAdjList();

_Bool adjNodeExistInAnotherAdjNode(struct adjNode* child, struct adjNode* parent);

int calculateAdjListDegree();

short* convertFromAdjListToAdjMatrix();

void printIncidenceMatrix(short *matrix);

void printAdjacencyMatrix(short *matrix);

void printAdjacencyList(struct adjList* graph);

_Bool pairExistInMatrix(int *matrix, int first, int second);

int main() {
    short choice = -1;
    while (choice != 3) {
        printf("\n----- MENU -----\n");
        printf("1. Enter a graph\n");
        printf("2. Display the graph\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%hi", &choice);
        printf("\n");

        switch (choice)
        {
        case 1:
        {
            short inputChoice = -1;
            printf("In what form do you want to enter the graph?\n");
            printf("1. Incidence Matrix\n");
            printf("2. Adjacency Matrix\n");
            printf("3. Adjacency List\n");
            printf("4. <- Go back\n");
            printf("Enter your choice: ");
            scanf("%hi", &inputChoice);

            switch (inputChoice)
            {
                case 1:
                {
                    vertices = getVerticesAmount();
                    edges = getEdgesAmount();
                    short* incMatrix = inputIncidenceMatrix();
                    adjListGraph = convertFromIncidenceMatrixToAdjList(incMatrix);
                    printf("Okay, what would you want to do next?");
                    break;
                }
                case 2:
                {
                    vertices = getVerticesAmount();
                    short* adjMatrix = inputAdjacencyMatrix();
                    adjListGraph = convertFromAdjMatrixToAdjList(adjMatrix);
                    break;
                }
                case 3:
                {
                    vertices = getVerticesAmount();
                    adjListGraph = inputAdjacencyList();
                    break;
                }
                case 4:
                {
                    printf("Ok, going back...\n");
                    break;
                }
                
                default:
                    printf("You have entered a wrong choice number.\n"
                    "You should enter a number between 1 and 4.\n"
                    "Please, try again...\n");
                    break;
            }
            break;
        }
            
        case 2:
        {
            if (adjListGraph == NULL) 
            {
                printf("X There's no graph, please enter a graph first. X\n");
            }
            else
            {
                short displayChoice = -1;
                printf("In what form do you want to display the graph?\n");
                printf("1. Incidence Matrix\n");
                printf("2. Adjacency Matrix\n");
                printf("3. Adjacency List\n");
                printf("4. <- Go back\n");
                printf("Enter your choice: ");
                scanf("%hi", &displayChoice);
                switch (displayChoice)
                {
                case 1:
                {
                    short* incMatrix = convertFromAdjListToIncidenceMatrix(adjListGraph);
                    printIncidenceMatrix(incMatrix);
                    free(incMatrix);
                    break;
                }
                case 2:
                {
                    short* adjMatrix = convertFromAdjListToAdjMatrix(adjListGraph);
                    printAdjacencyMatrix(adjMatrix);
                    free(adjMatrix);
                    break;
                }
                case 3:
                {
                    printAdjacencyList(adjListGraph);
                    break;
                }
                case 4:
                {
                    printf("Ok, going back...\n");
                    break;
                }
                
                default:
                    printf("You have entered a wrong choice number.\n"
                    "You should enter a number between 1 and 4.\n"
                    "Please, try again...\n");
                    break;
                }
            }

            break;
        }

        case 3:
        {
            (void)free(adjListGraph);
            printf("Have a nice day!\n");
            break;
        }
        default:
            printf("You have entered a wrong choice number.\n"
            "You should enter a number between 1 and 3.\n"
            "Please, try again...\n");
            break;
        }
    }

    return 0;
}

short* inputIncidenceMatrix() {
    short *incMatrix = (short *)calloc(vertices * edges, sizeof(short));
    printf("Please fill the matrix with values:\n");
    for (int i = 0; i < edges; ++i)
    {
        for (int j = 0; j < vertices; ++j)
        {
            scanf("%hi", &incMatrix[i*vertices + j]);
        }
    }

    printf("\nThis is the entered Incidence Matrix:\n");
    printIncidenceMatrix(incMatrix);
    printf("\nDo you want to edit it? (y/n): ");
    char choice = 'n';
    getchar();
    scanf("%c", &choice);
    while (choice == 'y')
    {
        editIncidenceMatrix(incMatrix);
        printf("\nThis is your new Incidence Matrix:\n");
        printIncidenceMatrix(incMatrix);
        printf("\nDo you want to edit it? (y/n): ");
        getchar();
        scanf("%c", &choice);
    }

    return incMatrix;
}

void editIncidenceMatrix(short* incMatrix)
{
    int edge = -1;
    int vertex = -1;
    short newValue = -1;
    printf("Type the number of edge you want to edit: ");
    scanf("%d", &edge);
    printf("Type the number of vertex you want to edit: ");
    scanf("%d", &vertex);
    edge--;
    vertex--;
    printf("\nIn place of the entered coordinates is the value %hi\n"
            "Please, type a new value: ", incMatrix[edge*edges + vertex]);
    scanf("%hi", &incMatrix[edge*edges + vertex]);
}

short* inputAdjacencyMatrix() {
    short *matrix = (short *)malloc(vertices * vertices * sizeof(short));
    printf("Please fill the matrix with values:\n");
    for (int i = 0; i < vertices; ++i)
    {
        for (int j = 0; j < vertices; ++j)
        {
            scanf("%d", &matrix[i*vertices + j]);
        }
    }

    printf("\nHere is the entered Adjacency Matrix:\n");
    printAdjacencyMatrix(matrix);

    printf("\nDo you want to edit it? (y/n): ");
    char choice = 'n';
    getchar();
    scanf("%c", &choice);
    while (choice == 'y')
    {
        editAdjacencyMatrix(matrix);
        printf("\nThis is your new Adjacency Matrix:\n");
        printAdjacencyMatrix(matrix);
        printf("\nDo you want to edit it? (y/n): ");
        getchar();
        scanf("%c", &choice);
    }

    return matrix;
}

void editAdjacencyMatrix(short* adjMatrix)
{
    int x = -1;
    int y = -1;
    short newValue = -1;
    printf("Type coordinates of a value you want to change(x y): ");
    scanf("%d %d", &x, &y);
    x--;
    y--;
    printf("\nIn place of the entered coordinates is the value %hi\n"
            "Please, type a new value: ", adjMatrix[y*vertices + x]);
    scanf("%hi", &adjMatrix[y*vertices + x]);
}

struct adjList* inputAdjacencyList() {
    struct adjList* graph = createAdjList(vertices);
    printf("Fill the list, when you're done with a vertex, type 0.\n");
    int v;
    for (v = 0; v < graph->numVertices; v++) {
        int value = -1;
        struct adjNode* temp = graph->adjLists[v];
        char str[255];
        strcpy(str, "Vertex ");
        char vPlusOne[10];
        sprintf(vPlusOne, "%d", v + 1);
        strcat(str, vPlusOne);
        strcat(str, ": ");
        printf("%s", str);
        while (value != 0) 
        {
            scanf("%d", &value);
            char strValue[10];
            sprintf(strValue, "%d", value);
            strcat(str, strValue);
            strcat(str, " -> ");
            printf("%s", str);
            if (value != 0)
            {
                addEdgeForAdjList(graph, v, value - 1);
            }
        }
        printf("\n\n");
    }

    printf("\nHere is the entered Adjacency List:\n");
    printAdjacencyList(graph);
    printf("\nDo you want to edit it? (y/n): ");
    char choice = 'n';
    getchar();
    scanf("%c", &choice);
    while (choice == 'y')
    {
        editAdjacencyList(graph);
        printf("\nThis is your new Adjacency List:\n");
        printAdjacencyList(graph);
        printf("\nDo you want to edit it? (y/n): ");
        getchar();
        scanf("%c", &choice);
    }

    return graph;
}

void editAdjacencyList(struct adjList* graph)
{
    int vertex, value, newValue;
    printf("Type number of vertex you want to edit: ");
    scanf("%d", &vertex);
    printf("Type a value you want to edit in vertex %d: ",
            vertex);
    scanf("%d", &value);
    printf("Enter a new value to replace the old one: ");
    scanf("%d", &newValue);
    vertex--;
    value--;
    newValue--;

    struct adjNode* temp = graph->adjLists[vertex];
    while (temp) 
    {
        if (temp->vertex == value)
        {
            temp->vertex = newValue;
            return;
        }
        temp = temp->next;
    }
}

int getVerticesAmount() {
    int vertices;
    printf("Please, enter number of vertices: ");
    scanf("%d", &vertices);

    return vertices;
}

int getEdgesAmount() {
    int edges;
    printf("Please, enter number of edges: ");
    scanf("%d", &edges);

    return edges;
}

void printIncidenceMatrix(short *matrix) {
    printf("      ");
    for (int b = 0; b < vertices; b++) {
        printf("[v%d]  ", b+1);
    }

    printf("\n    +");
    for (int b = 0; b < vertices; b++) {
        printf("-----");
    }
    printf("+\n");
    for (int i = 0; i < edges; i++) {
        printf("[e%d] | ", i+1);
        for (int j = 0; j < vertices; j++) {
            if (matrix[i*vertices + j] < 0) {
                printf(" %d  ", matrix[i*vertices + j]);
            } else {
                printf(" %d   ", matrix[i*vertices + j]);
            }
        }
        printf("\n");
    }
}

void printAdjacencyMatrix(short *matrix) {
    printf("      ");
    for (int b = 0; b < vertices; b++) {
        printf("[v%d] ", b+1);
    }

    printf("\n     +");
    for (int b = 0; b < vertices; b++) {
        printf("-----");
    }
    printf("+\n");
    for (int i = 0; i < vertices; i++) {
        printf("[v%d] | ", i+1);
        for (int j = 0; j < vertices; j++) {
            if (matrix[i*vertices + j] < 0) {
                printf(" %d  ", matrix[i*vertices + j]);
            } else {
                printf(" %d   ", matrix[i*vertices + j]);
            }
        }
        printf("\n");
    }
}

void printAdjacencyList(struct adjList* graph) {
    if (graph)
    {
        int v;
        for (v = 0; v < graph->numVertices; v++) 
        {
            struct adjNode* temp = graph->adjLists[v];
            printf("\n Vertex %d: ", v + 1);
            while (temp) 
            {
                printf("%d -> ", (temp->vertex) + 1);
                temp = temp->next;
            }
            printf("0\n");
        }
    }
    else
    {
        printf("\nX There is no graph. X\n");
    }
    
}

struct adjNode* createNodeForAdjList(int v) {
    struct adjNode* newNode = (struct adjNode*)calloc(1, sizeof(struct adjNode));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct adjList* createAdjList() {
    if (adjListGraph)
    {
        freeAdjList(adjListGraph);
    }

    struct adjList* graph =  (struct adjList*)calloc(1, sizeof(struct adjList));
    graph->numVertices = vertices;

    graph->adjLists = (struct adjNode**)calloc(vertices, sizeof(struct adjNode*));

    int i;
    for (i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

void addEdgeForAdjList(struct adjList* graph, int s, int d) {
    struct adjNode* newNode = createNodeForAdjList(d);
    if (graph->adjLists[s])
    {
        struct adjNode* temp = graph->adjLists[s];
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    else
    {
        graph->adjLists[s] = newNode;
    }

}

struct adjList* convertFromIncidenceMatrixToAdjList(short* incMatrix) 
{
    if (incMatrix != NULL && vertices != 0) 
    {
        struct adjList* resultList = createAdjList(vertices);
        _Bool bIsMatrixDirected = isIncMatrixDirected(incMatrix);
        if (bIsMatrixDirected)
        {
            convertFromDirectedIncidenceMatrixToAdjList(incMatrix, resultList);
        } 
        else
        {
            convertFromUndirectedIncidenceMatrixToAdjList(incMatrix, resultList);
        }

        free(incMatrix);
        return resultList;   
    } 

    (void)free(incMatrix);
    return NULL;
}

_Bool isIncMatrixDirected(short* incMatrix)
{
    for (int i = 0; i < edges; i++) 
    {
        for (int j = 0; j < vertices; j++) 
        {
            if (incMatrix[i*vertices + j] == -1)
            {
                return 1;
            }
        }
    }

    return 0;
}

void convertFromUndirectedIncidenceMatrixToAdjList(short* incMatrix, struct adjList* resultList)
{
    int in = -1;
    int out = -1;
    for (int i = 0; i < edges; i++) 
    {
        for (int j = 0; j < vertices; j++) 
        {
            if (incMatrix[i*vertices + j] == 1)
            {
                if (in == -1)
                {
                    in = j;
                }
                else if (out == -1)
                {
                    out = j;
                    addEdgeForAdjList(resultList, in, out);
                    addEdgeForAdjList(resultList, out, in);
                    in = -1;
                    out = -1;
                }
            }
        }
    }
}

void convertFromDirectedIncidenceMatrixToAdjList(short* incMatrix, struct adjList* resultList)
{
    int in = -8;
    int out = -8;
    for (int i = 0; i < edges; i++) 
    {
        for (int j = 0; j < vertices; j++) 
        {
            if (incMatrix[i*vertices + j] == -1)
            {
                in = j;
            }
            else if (incMatrix[i*vertices + j] == 1)
            {
                out = j;
            }

            if (in != -8 && out != -8)
            {
                addEdgeForAdjList(resultList, in, out);
                in = -8;
                out = -8;
            }
        }
    }
}

struct adjList* convertFromAdjMatrixToAdjList(short* matrix) 
{
    struct adjList* result;
    if (isAdjMatrixDirected(matrix))
    {
        result = convertFromDirectedAdjMatrixToAdjList(matrix);
    }
    else
    {
        result = convertFromUndirectedAdjMatrixToAdjList(matrix);
    }

    free(matrix);
    matrix = NULL;

    return result;
}

_Bool isAdjMatrixDirected(short *adjMatrix)
{
    int* sliceOfMatrix = calloc(vertices*2, sizeof(int));
    int elementsCounter = 0;
    int checkCounter = 0;
    // Top triangle of the matrix
    for (int i = 0; i < vertices; i++)
    {
        for (int j = i+1; j < vertices; j++)
        {
            sliceOfMatrix[elementsCounter++] = adjMatrix[i*vertices + j];
        }
    }
    // Bottom triangle of the matrix
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (checkCounter <= elementsCounter &&
                sliceOfMatrix[checkCounter++] != adjMatrix[i*vertices + j])
            {
                return 1;
            }
        }
    }

    free(sliceOfMatrix);
    sliceOfMatrix = NULL;
    return 0;
}

struct adjList* convertFromDirectedAdjMatrixToAdjList(short *adjMatrix)
{
    struct adjList* graph = createAdjList(vertices);
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            if (adjMatrix[i*vertices + j] == 1)
            {
                addEdgeForAdjList(graph, i, j);
            }
        }
    }

    return graph;
}

struct adjList* convertFromUndirectedAdjMatrixToAdjList(short *adjMatrix)
{
    struct adjList* graph = createAdjList(vertices);
    int in = -1;
    int out = -1;
    for (int i = 0; i < vertices; i++)
    {
        in = i;
        for (int j = 0; j < vertices; j++)
        {
            if (adjMatrix[i*vertices + j] == 1)
            {
                out = j;
                addEdgeForAdjList(graph, in, out);
            }
        }
    }

    return graph;
}

short* convertFromAdjListToIncidenceMatrix()
{
    if (adjListGraph)
    {
        if (isIncMatrixDirectedCheckByAdjList())
        {
            printf("\nThe graph is directed\n");
            return convertFromAdjListToDirectedIncidenceMatrix();
        } 
        else
        {
            printf("\nThe graph is undirected\n");
            return convertFromAdjListToUndirectedIncidenceMatrix();
        }
    }
    else
    {
        printf("\nX There is no graph. X\n");
        return NULL;
    }
    
}

short* convertFromAdjListToUndirectedIncidenceMatrix()
{
    int listDegree = calculateAdjListDegree();
    edges = listDegree / 2;
    short *matrix = (short *)calloc(edges * vertices, sizeof(short));
    int helperSize = edges * 2;
    int *helperMatrix = (int *)calloc(helperSize * 2, sizeof(int));
    int helperCounter = 0;
    int v;
    int edgeCounter = 0;
    for (v = 0; v < adjListGraph->numVertices; v++) 
    {
        struct adjNode* temp = adjListGraph->adjLists[v];
        while (temp) 
        {
            if (!pairExistInMatrix(helperMatrix, v, temp->vertex) 
                && edgeCounter < edges)
            {
                matrix[edgeCounter*edges + v] = 1;
                matrix[edgeCounter*edges + (temp->vertex)] = 1;
                edgeCounter++;
                helperMatrix[helperCounter*helperSize] = v;
                helperMatrix[helperCounter*helperSize + 1] = temp->vertex;
                helperCounter++;
            }
            temp = temp->next;
        }
    }
    free(helperMatrix);
    helperMatrix = NULL;
    return matrix;
}

short* convertFromAdjListToDirectedIncidenceMatrix()
{
    edges = calculateAdjListDegree();
    short *matrix = (short *)calloc(edges * vertices, sizeof(short));
    int rowCounter = 0;
    struct adjNode* temp;
    for (int v = 0; v < adjListGraph->numVertices; v++) 
    {
        temp = adjListGraph->adjLists[v];
        while (temp) 
        {
            matrix[rowCounter*vertices + v] = -1;
            matrix[rowCounter*vertices + temp->vertex] = 1;
            rowCounter++;
            temp = temp->next;
        }
    }

    return matrix;
}

int calculateAdjListDegree()
{
    int listDegree = 0;
    for (int v = 0; v < adjListGraph->numVertices; v++) 
    {
        struct adjNode* temp = adjListGraph->adjLists[v];
        while (temp) 
        {
            listDegree++;
            temp = temp->next;
        }
    }

    return listDegree;
}

_Bool isIncMatrixDirectedCheckByAdjList()
{
    struct adjNode *node, *next;
    for (int v = 0; v < adjListGraph->numVertices; v++) 
    {
        node = adjListGraph->adjLists[v];
        while (node) 
        {
            next = node->next;
            if (!adjNodeExistInAnotherAdjNode(node, next))
            {
                return 1;
            }
        }
    }

    return 0;
}

_Bool adjNodeExistInAnotherAdjNode(struct adjNode* child, struct adjNode* parent)
{
    while (parent) 
    {
        parent = parent->next;
        if (parent == child)
        {
            return 1;
        }
    }

    return 0;
}

_Bool pairExistInMatrix(int *matrix, int first, int second)
{
    int n = edges * 2;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            if (((matrix[i*n + j] == first) && (matrix[i*n + j+1] == second))
                || ((matrix[i*n + j] == second) && (matrix[i*n + j+1] == first)))
            {
                return 1;
            }
        }
    }
    return 0;
}

short* convertFromAdjListToAdjMatrix()
{
    if (adjListGraph)
    {
        short *matrix = (short *)calloc(vertices * vertices, sizeof(short));
        int v;
        for (v = 0; v < adjListGraph->numVertices; v++) 
        {
            struct adjNode* temp = adjListGraph->adjLists[v];
            while (temp) 
            {
                matrix[v*vertices + temp->vertex] = 1;
                temp = temp->next;
            }
        }

        return matrix;
    }
    else
    {
        printf("\nX There is no graph. X\n");
        return NULL;
    }
}

void freeAdjList(struct adjList* list)
{
    if (list)
    {
        for (int v = 0; v < list->numVertices; v++) 
        {
            struct adjNode* head = list->adjLists[v];
            while (head) 
            {
                struct adjNode* temp = head;
                head = head->next;
                free(temp);
            }
        }
        free(list->adjLists);
        free(list);
    }
}