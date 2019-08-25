#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename W>
struct Edge
{
	Edge(const W& w)
		: m_src_index(0)
		, m_dst_index(0)
		, m_w(w)
		, m_next(nullptr)
	{}
	size_t m_src_index;
	size_t m_dst_index;
	W m_w;
	Edge<W> * m_next;
};

template <typename V, typename W, bool IsDirect = false>
class Graph
{
	typedef Edge<W> Edge;
public:
	Graph(const V* v, size_t n)
	{
		m_vertex.resize(n);
		for (size_t i = 0; i < n; i++)
		{
			m_vertex[i] = v[i];
		}
		m_link_table.resize(n, nullptr);
	}

	size_t GetVertexIndex(const V& v)
	{
		for (size_t i = 0; i < m_vertex.size(); ++i)
		{
			if (m_vertex[i] == v)
				return i;
		}
		throw invalid_argument("非法的顶点");
	}

	void _AddEdge(size_t srcIndex, size_t dstIndex, const W& w)
	{
		Edge* edge = new Edge(w);
		edge->m_src_index = srcIndex;
		edge->m_dst_index = dstIndex;
		edge->m_next = m_link_table[srcIndex];
		m_link_table[srcIndex] = edge;
	}

	void AddEdge(const V& src, const V& dst, const W& w)
	{
		size_t srcIndex = GetVertexIndex(src);
		size_t dstIndex = GetVertexIndex(dst);
		
		_AddEdge(srcIndex, dstIndex, w);
		if (IsDirect == false)
		{
			_AddEdge(dstIndex, srcIndex, w);
		}
	}
private:
	std::vector<V> m_vertex;
	std::vector<Edge*> m_link_table;
};

int main()
{
	std::string str[] = { "詹姆斯", "杜兰特", "库里", "韦德", "安东尼.戴维斯", "保罗" };
	Graph <string, int> socialGraph(str, sizeof(str)/sizeof(str[0]));
	socialGraph.AddEdge("詹姆斯", "安东尼.戴维斯", 80);
	socialGraph.AddEdge("詹姆斯", "保罗", 90);
	socialGraph.AddEdge("詹姆斯", "韦德", 95);
	socialGraph.AddEdge("库里", "杜兰特", 80);
	return 0;
}

//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//template <typename V, typename W, bool IsDirect = false>
//class Graph
//{
//public:
//	Graph(const V* v, size_t n)
//	{
//		m_v.resize(n);
//		for (size_t i = 0; i < n; i++)
//		{
//			m_v[i] = v[i];
//		}
//		m_edges.resize(n);
//		for (auto & e : m_edges)
//			e.resize(n, 0);
//	}
//
//	size_t GetVertexIndex(const V& v)
//	{
//		for (size_t i = 0; i < m_v.size(); ++i)
//		{
//			if (m_v[i] == v)
//				return i;
//		}
//		throw invalid_argument("非法的顶点");
//	}
//
//	void AddEdge(const V& src, const V& dst, const W& w)
//	{
//		size_t srcIndex = GetVertexIndex(src);
//		size_t dstIndex = GetVertexIndex(dst);
//		m_edges[srcIndex][dstIndex] = w;
//		if (IsDirect == false)
//		{
//			m_edges[dstIndex][srcIndex] = w;
//		}
//	}
//private:
//	std::vector<V> m_v;
//	std::vector<std::vector<int> > m_edges;
//};
//
//int main()
//{
//	std::string str[] = { "詹姆斯", "杜兰特", "库里", "韦德", "安东尼.戴维斯", "保罗" };
//	Graph <string, int> socialGraph(str, sizeof(str)/sizeof(str[0]));
//	socialGraph.AddEdge("詹姆斯", "安东尼.戴维斯", 80);
//	socialGraph.AddEdge("詹姆斯", "保罗", 90);
//	socialGraph.AddEdge("詹姆斯", "韦德", 95);
//	socialGraph.AddEdge("库里", "杜兰特", 80);
//	return 0;
//}
