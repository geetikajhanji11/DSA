/*******************************************************************
BOARD GAME



----------- ANOTHER APPROACH -----------

class Node {
    public:
    char ch;
    unordered_map<char, Node*> children;
    bool isTerminal;
    string word;

    Node(char ch) {
        this->ch = ch;
        this->word = "";
        this->isTerminal = false;
    }
};

class Trie {
    public:
    Node* root;

    Trie() {
        this->root = new Node('\0');
    }

    void insert(string word) {
        Node* temp = root;
        for(char ch : word) {
            if(temp->children.count(ch) == 0) {
                temp->children[ch] = new Node(ch);
            }
            temp = temp->children[ch];
        }
        temp->isTerminal = true;
        temp->word = word;
    }
};

vector<int> di = {0, 1 , 1 ,1, 0, -1, -1,-1};
vector<int> dj = {-1,-1, 0, 1, 1, 1, 0, -1};

bool in_bounds(int i, int j, vector<vector<char>> &board) {
    return i >= 0 && i < board.size() && j >= 0 && j < board[0].size();
}

void find_words(int i, int j, Node* root, vector<vector<char>> &board, vector<vector<int>> visited, vector<string> &result) {
    
    if(!in_bounds(i, j, board)) return;

    if(visited[i][j]) return;

    if(root->isTerminal) {
        result.push_back(root->word);
    }

    visited[i][j] = true;

    for(int k=0; k<8; k++) {
        int next_i = i + di[k];
        int next_j = j + dj[k];
        if(!in_bounds(next_i, next_j, board)) continue;
        for(auto child=root->children.begin(); child != root->children.end(); child++) {
            char child_ch = child->first;
            Node* child_node = child->second;
            if(child_ch == board[next_i][next_j]) {
                find_words(next_i, next_j, child_node, board, visited, result);

            }
        }
    }

    visited[i][j] = false;
}

void board_game(vector<vector<char>> &board, vector<string> &words) {
    Trie t;
    for(string word : words) {
        t.insert(word);
    }
    vector<string> result;
    int m = board.size();
    int n = board[0].size();
    vector<vector<int>> visited(m, vector<int>(n, 0));

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            find_words(i, j, t.root, board, visited, result);
        }
    }

    int i = 0;

    set<string> s(result.begin(), result.end());
    for(string str : s) {
        cout<<i<<": ";
        cout<<str<<endl;
        i++;
    }

}


int main() {

    vector<string> words = {"EKT", "SNAKE", "FOR", "QUEZ", "SNACK", "SNACKS", "GO","TUNES","CAT"};
    
    vector<vector<char>> board = { 
        { 'S', 'E', 'R' ,'T'}, 
        { 'U', 'N', 'K' ,'S'},
        { 'T', 'C', 'A' ,'T'} 
    };

    board_game(board, words);

    return 0;
}

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define M 3 
#define N 4 

class Node{
public:
	char s;
	unordered_map<char,Node*> children;
	string word;
	bool isTerminal;

	Node(char s){
		this->s = s;
		isTerminal = false;
		word = "";
	}
};

class Trie{
public:
	Node*root;

	Trie(){
		root = new Node('\0');
	}

	void addWord(string word){

		Node * temp = root;
		for(auto ch : word){
			if(temp->children.count(ch)==0){
				temp->children[ch] = new Node(ch);
			}
			temp = temp->children[ch];
		}
		//last node
		temp->isTerminal = true;
		temp->word = word;
	}
};


//main algorithm (8-way dfs + trie guided search)

void dfs(char board[M][N],Node *node,int i,int j,bool visited[][N], unordered_set<string> &output){

	//base case
	char ch = board[i][j];
	if(node->children.count(ch)==0){
		return;
	}

	//otherwise trie contains this node
	visited[i][j] = true;
	node = node->children[ch];


	// if it is a terminal node in the trie 
	if(node->isTerminal){
		output.insert(node->word);
	}

	//explore the neigbours 
    int dx[] = {0, 1 , 1 ,1, 0, -1, -1,-1};
	int dy[] = {-1,-1, 0, 1, 1, 1, 0, -1};

	for(int k=0;k<8;k++){

		int ni = i + dx[k];
		int nj = j + dy[k];

		//if it is in bounds and is not visited
		if(ni>=0 and nj>=0 and ni < M and nj < N and !visited[ni][nj]){
			dfs(board,node,ni,nj,visited,output);
		}
	}
	//last step (backtracking)
	visited[i][j] = false;
	return;
}


int main() {
    

    
    string words[] = {"SNAKE", "FOR", "QUEZ", "SNACK", "SNACKS", "GO","TUNES","CAT"};
    
    char board[M][N] = { { 'S', 'E', 'R' ,'T'}, 
                          { 'U', 'N', 'K' ,'S'},
                          { 'T', 'C', 'A' ,'T'} };

     //1. Trie

      Trie t;
      for(auto w : words){
      	t.addWord(w);
      }

      //2. Take a container to store words that are found in dfs search
      unordered_set<string> output;


      //3. Step (8-DFS Search from every cell)
      bool visited[M][N] =  {0};


      for(int i=0; i<M;i++){
      	for(int j=0;j<N;j++){
      		dfs(board,t.root,i,j,visited,output);
      		//reset the visited array after every call (while backtracking)
      	}
      }

      //4. Print the Output

      for(auto word: output){
      	cout<< word <<endl;
      }


    return 0;
}