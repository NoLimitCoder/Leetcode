#define deb(x) cout << #x << ": " << x << '\n'
#define debl(x) cout << #x << ": " << x << ' '

//adapted from Sebastian Dionicio's (me) code for IOI 2013 Dreaming

typedef vector<int> VI;
typedef pair<int,int> II;
const int INF  = 1000000010;

class Solution {
public:

struct Edge {
	int to, weight;
};
typedef vector< vector<Edge> > Graph; 

Graph billabongs;
vector<bool> vis;
VI component;

void dfs1(int src){
	vis[src] = true;
	component.push_back(src);
	for(Edge e : billabongs[src]){
		if(vis[e.to]) continue;
		dfs1(e.to);
	}
}
 
void dfs2(const Graph& tree, VI& D, int u, int d = 0) {
   D[u] = d;
   for (Edge e : tree[u]) {
      if (D[e.to] >= 0) continue;
      dfs2(tree, D, e.to, d+e.weight);
   }
}
 
II get_center_points(const Graph& tree) {
   const int n = tree.size();
   if (n == 1)
      return {0, 0};
//Longest path in a tree
// 	finding first endpoint of the tree
	VI D1(n,-1);
	int u_max = 0;
	dfs2(tree,D1,0);
	for(int u = 0; u < n; ++u) {
	if (D1[u] > D1[u_max])
		u_max = u;
   }
	//deb(u_max);
//	finding the second endpoint of the tree
	VI D2(n,-1);
	int v_max = 0;
	dfs2(tree,D2,u_max);
	for(int v = 0; v < n; ++v) {
		if (D2[v] > D2[v_max])
			v_max = v;
   }
	//deb(v_max);
//	filling the Distances for the second endpoint
	VI D3(n,-1);
	dfs2(tree,D3,v_max);
// 	finding the "center point"
	II best = {INF,INF}, temp;
	for(int u = 0; u < n; ++u){
		if(D2[u] > D3[u])
			temp = {D2[u], D3[u]};
		else
			temp = {D3[u], D2[u]};
		best = min(best,temp);
	}
	return best;
}
 
 
Graph renumerate(){
	map<int,int> new_id;
	int n = (int) component.size();
	for(int i = 0; i < n; ++i)
		new_id[component[i]] = i;
	Graph tree(n);
	for(int u : component){
		int new_id_of_u = new_id[u];
		for(Edge e : billabongs[u]){
			int new_id_of_v = new_id[e.to];
			tree[new_id_of_u].push_back({new_id_of_v, e.weight});
			//tree[new_id_of_v].push_back({new_id_of_u, e.weight}); not added because it was previously
		}
	}
	return tree;
}
 
 
int travelTime(int N, int M, int L, VI A, VI B, VI T){
	//First part representing the Graph
	billabongs = Graph(N);
	for(int i = 0; i < M; ++i){
		int u = A[i], v = B[i], weight = T[i];
		billabongs[u].push_back({v,weight});
		billabongs[v].push_back({u,weight});
	}
	vis = vector<bool>(N,false);
	vector<Graph> trees;
	//Second part getting the connected components (trees)
	for(int i = 0; i < N; ++i){
		if(vis[i]) continue;
		component = VI(0);
		dfs1(i);
	//Third part renumerating the ids of the nodes of the trees
		Graph tree = renumerate();
		trees.emplace_back(tree);
	}
	//for testing
	
	/*int comp = 0;
	for(Graph tree : trees){
			cout << "component # " << comp++ << '\n';
			for(int j = 0; j < (int)tree.size(); ++j){
			cout << "Node: " << j << '\n';
			for(Edge e : tree[j]){
				cout << "e.to: " << e.to << " e.weight: " << e.weight << '\n';
			}
		}
	}*/
	
	//Fourth part getting the center points of the trees
	vector<II> center_points;
	for(Graph tree : trees){
		II center_point = get_center_points(tree);
		//cerr <<"center_point: " << center_point.first << ' ' << center_point.second << '\n';
		center_points.push_back(center_point);
	}
	sort(center_points.begin(), center_points.end(), greater<II>());
	int ans = 0;
	 //checking if the longest path is on the current tree;
	for (II center_point : center_points)
		ans = max(ans, center_point.first + center_point.second);
	//checking if there are 2 or more center points
	if (int(center_points.size()) > 1) {		
		ans = max(ans,center_points[0].first + L + center_points[1].first);
	for (int i = 2; i < int(center_points.size()); ++i) {
		ans = max(ans, center_points[i].first + 2*L + center_points[1].first);
      }
   }
    return ans;
}



    int minimumDiameterAfterMerge(vector<vector<int>>& e1, vector<vector<int>>& e2) {
        //making this problem an instance of IOI 2013 Dreaming
        int m = e1.size() + e2.size();
        int n = m + 2;
        int l = 1;
        vector<int> A(n), B(n), T(n);
        //debl(n); debl(m); deb(l);
        for(int i = 0; i<e1.size(); ++i){
            A[i] = e1[i][0];
            B[i] = e1[i][1];
            T[i] = 1;
            //debl(A[i]); deb(B[i]);
        }
        int ex = e1.size();
        for(int i = 0; i<e2.size(); ++i){
            A[ex+i] = ex + e2[i][0]+1;
            B[ex+i] = ex + e2[i][1]+1;
            T[ex+i] = 1;
            //debl(A[ex+i]); debl(B[ex+i]); deb(ex+i); 
        }
        /*for(int i = 0; i<n; ++i){
            cout << A[i] << ' ' << B[i] << ' ' << T[i] << '\n';
        }*/
        //solve
        return travelTime(n,m,l,A,B,T);
    }
};
