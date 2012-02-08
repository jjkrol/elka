/* ze względu na to, że kod był pisany cały za jednym razem, wszystko jest w jednym pliku 
 * 
 * program realizuje graf nieskierowany, a powinien być skierowany (inaczej wtedy można trzymać krawędzie i wierzchołki
 * zabrali mi za to jeden punkt
 * */

#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<set>
#include<cmath>

using namespace std;

class Graph{
	public:
		typedef struct Point{
			float x;
			float y;
		} Point;
		typedef struct Edge{
			int firstVertex;
			int secondVertex;
			float weightGiven;
			float weightGeometrical;
		} Edge;
		void	manageLine();
		void	dijkstra(int, int, bool);
		Graph(){};
		~Graph(){};
	private:
		typedef struct Distance{
			int vertex;
			float distance;
			friend bool operator<(Distance const& a, Distance const& b)
			{
				return a.distance<b.distance;
			}
		} Distance;
		vector<float> distances;
		void	readLastLine(string line, int spacePos);
		void	readSecondSection(string line, int firstSpacePos, int secondSpacePos);
		void	readFirstSection(string line, int spacePos);
		bool	mySortFunction(int, int);
		vector<Edge>	getNeighbours(int);
		std::pair<bool, vector<Edge>::iterator> checkForDuplicates(int, int);

		vector<Point> points;
		vector<Edge> edges;

};


int main(int argc, char * argv){
	Graph * graf = new Graph();
	graf->manageLine();
	return 0;
}

void	Graph::manageLine(){
	string line;
	bool afterFirstSection = false;
	while(getline(cin, line)){
		int firstSpace = line.find(" ");
		int lastSpace = line.rfind(" ");
		if(firstSpace == lastSpace){
			if(!afterFirstSection){
				readFirstSection(line, firstSpace);
			}
			else{
				readLastLine(line, firstSpace);
				return;
			}
		}
		else{
			readSecondSection(line, firstSpace, lastSpace);
			afterFirstSection = true;
		}
	}
}

void	Graph::readFirstSection(string line, int spacePos){
	stringstream ss;
	Point newPoint;
	ss << line;
	ss >> newPoint.x;
	ss >> newPoint.y;
	points.push_back(newPoint);
}

void	Graph::readSecondSection(string line, int firstSpacePos, int secondSpacePos){
	stringstream ss;
	Edge newEdge;
	ss << line;
	ss >> newEdge.firstVertex;
	ss >> newEdge.secondVertex;
	ss >> newEdge.weightGiven;
	float dx = abs(points[newEdge.firstVertex].x-points[newEdge.secondVertex].x);
	float dy = abs(points[newEdge.firstVertex].y-points[newEdge.secondVertex].y);
	newEdge.weightGeometrical = sqrt(dx*dx+dy*dy);
	pair<bool, vector<Edge>::iterator> result = checkForDuplicates(newEdge.firstVertex, newEdge.secondVertex);
	if(result.first){
		edges.erase(result.second);
	}
	edges.push_back(newEdge);

}

void	Graph::readLastLine(string line, int spacePos){
	int firstVertex, secondVertex;
	stringstream ss;
	ss << line;
	ss >> firstVertex;
	ss >> secondVertex;
	dijkstra(0,4,false);
	dijkstra(0,4,true);
}

void Graph::dijkstra(int mainVertex, int endVertex, bool geo){
	int v;
	Edge nextEdge;
	vector<int> previous;
	vector<Edge> neighbours;
	set<Distance> Q;
	set<int> used;
	Point u;

	for (int i = 0; i < points.size(); i++) {
		if(i==mainVertex) distances.push_back(0);
		else distances.push_back(-1); //nieskonczonosc
		previous.push_back(-1);
	}

	Distance d;
	d.vertex = mainVertex;
	d.distance = 0;
	Q.insert(d);

	while(Q.size()>0){
		set<Distance>::iterator it = Q.begin();
		int i = (*it).vertex;
		Q.erase(it);
		used.insert(i);
		neighbours = getNeighbours(i);
		for(int j = 0; j < neighbours.size(); j++){
			nextEdge = neighbours[j];
			if(nextEdge.firstVertex == i)
				v = nextEdge.secondVertex;
			else
				v =nextEdge.firstVertex;
			float weight = (geo)?nextEdge.weightGeometrical:nextEdge.weightGiven;

			if(distances[v] == -1 || distances[v] > distances[i] + weight){
				distances[v] = distances[i] + weight;
				previous[v] = i;
				if(used.find(v)==used.end()){
					Distance d;
					d.vertex = v;
					d.distance = distances[v];
					Q.insert(d);
				}
			}
		}

	}
	int i = endVertex;
	while(i != mainVertex){
		cout<<i<<" ";
		i = previous[i];
	}
	cout<<mainVertex<<" "<<distances[endVertex]<<endl;
	distances.clear();
}
bool Graph::mySortFunction(int i, int j){
	return (distances[i]<distances[j]);
}

vector<Graph::Edge>	Graph::getNeighbours(int vertex){
	vector<Edge>::iterator it;
	vector<Edge> neighbours;
	for(it = edges.begin(); it!=edges.end(); it++){
		if ((*it).firstVertex==vertex || (*it).secondVertex==vertex) {
			neighbours.push_back(*it);
		}
	}
	return neighbours;
}

std::pair<bool, vector<Graph::Edge>::iterator>	Graph::checkForDuplicates(int firstVertex, int secondVertex){
	vector<Edge>::iterator it;
	for(it = edges.begin(); it!=edges.end(); it++){
		if (((*it).firstVertex==firstVertex && (*it).secondVertex == secondVertex)
				|| ((*it).secondVertex==firstVertex && (*it).firstVertex == secondVertex)) {
			return make_pair(true, it);
		}
	}
	return make_pair(false, edges.end());	
}


















