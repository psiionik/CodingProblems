// #include <iostream>
// #include <vector>
// #include <string>
// #include <utility>                   // for std::pair
// #include <algorithm>                 // for std::for_each
// #include <numeric>
// //=======================================================================
// // Copyright 1997, 1998, 1999, 2000 University of Notre Dame.
// // Copyright 2010 Thomas Claveirole
// // Authors: Andrew Lumsdaine, Lie-Quan Lee, Jeremy G. Siek, Thomas Claveirole
// //
// // Distributed under the Boost Software License, Version 1.0. (See
// // accompanying file LICENSE_1_0.txt or copy at
// // http://www.boost.org/LICENSE_1_0.txt)
// //=======================================================================

// #ifndef BOOST_GRAPH_ADJACENCY_LIST_HPP
// #define BOOST_GRAPH_ADJACENCY_LIST_HPP

// #include <boost/config.hpp>

// #include <vector>
// #include <list>
// #include <set>

// #include <boost/unordered_set.hpp>

// #include <boost/scoped_ptr.hpp>

// #include <boost/graph/graph_traits.hpp>
// #include <boost/graph/graph_mutability_traits.hpp>
// #include <boost/graph/graph_selectors.hpp>
// #include <boost/property_map/property_map.hpp>
// #include <boost/mpl/if.hpp>
// #include <boost/mpl/and.hpp>
// #include <boost/mpl/not.hpp>
// #include <boost/mpl/bool.hpp>
// #include <boost/graph/detail/edge.hpp>
// #include <boost/type_traits/is_same.hpp>
// #include <boost/detail/workaround.hpp>
// #include <boost/graph/properties.hpp>
// #include <boost/graph/named_graph.hpp>

// namespace boost
// {

// //===========================================================================
// // Selectors for the VertexList and EdgeList template parameters of
// // adjacency_list, and the container_gen traits class which is used
// // to map the selectors to the container type used to implement the
// // graph.

// struct vecS
// {
// };
// struct listS
// {
// };
// struct setS
// {
// };
// struct mapS
// {
// };
// struct multisetS
// {
// };
// struct multimapS
// {
// };
// struct hash_setS
// {
// };
// struct hash_mapS
// {
// };
// struct hash_multisetS
// {
// };
// struct hash_multimapS
// {
// };

// template < class Selector, class ValueType > struct container_gen
// {
// };

// template < class ValueType > struct container_gen< listS, ValueType >
// {
//     typedef std::list< ValueType > type;
// };

// template < class ValueType > struct container_gen< vecS, ValueType >
// {
//     typedef std::vector< ValueType > type;
// };

// template < class ValueType > struct container_gen< mapS, ValueType >
// {
//     typedef std::set< ValueType > type;
// };

// template < class ValueType > struct container_gen< setS, ValueType >
// {
//     typedef std::set< ValueType > type;
// };

// template < class ValueType > struct container_gen< multisetS, ValueType >
// {
//     typedef std::multiset< ValueType > type;
// };

// template < class ValueType > struct container_gen< multimapS, ValueType >
// {
//     typedef std::multiset< ValueType > type;
// };

// template < class ValueType > struct container_gen< hash_setS, ValueType >
// {
//     typedef boost::unordered_set< ValueType > type;
// };

// template < class ValueType > struct container_gen< hash_mapS, ValueType >
// {
//     typedef boost::unordered_set< ValueType > type;
// };

// template < class ValueType > struct container_gen< hash_multisetS, ValueType >
// {
//     typedef boost::unordered_multiset< ValueType > type;
// };

// template < class ValueType > struct container_gen< hash_multimapS, ValueType >
// {
//     typedef boost::unordered_multiset< ValueType > type;
// };

// template < class StorageSelector > struct parallel_edge_traits
// {
// };

// template <> struct parallel_edge_traits< vecS >
// {
//     typedef allow_parallel_edge_tag type;
// };

// template <> struct parallel_edge_traits< listS >
// {
//     typedef allow_parallel_edge_tag type;
// };

// template <> struct parallel_edge_traits< setS >
// {
//     typedef disallow_parallel_edge_tag type;
// };

// template <> struct parallel_edge_traits< multisetS >
// {
//     typedef allow_parallel_edge_tag type;
// };

// template <> struct parallel_edge_traits< hash_setS >
// {
//     typedef disallow_parallel_edge_tag type;
// };

// // mapS is obsolete, replaced with setS
// template <> struct parallel_edge_traits< mapS >
// {
//     typedef disallow_parallel_edge_tag type;
// };

// template <> struct parallel_edge_traits< hash_mapS >
// {
//     typedef disallow_parallel_edge_tag type;
// };

// template <> struct parallel_edge_traits< hash_multisetS >
// {
//     typedef allow_parallel_edge_tag type;
// };

// template <> struct parallel_edge_traits< hash_multimapS >
// {
//     typedef allow_parallel_edge_tag type;
// };

// namespace detail
// {
//     template < class Directed > struct is_random_access
//     {
//         enum
//         {
//             value = false
//         };
//         typedef mpl::false_ type;
//     };
//     template <> struct is_random_access< vecS >
//     {
//         enum
//         {
//             value = true
//         };
//         typedef mpl::true_ type;
//     };

// } // namespace detail

// template < typename Selector > struct is_distributed_selector : mpl::false_
// {
// };

// //===========================================================================
// // The adjacency_list_traits class, which provides a way to access
// // some of the associated types of an adjacency_list type without
// // having to first create the adjacency_list type. This is useful
// // when trying to create interior vertex or edge properties who's
// // value type is a vertex or edge descriptor.

// template < class OutEdgeListS = vecS, class VertexListS = vecS,
//     class DirectedS = directedS, class EdgeListS = listS >
// struct adjacency_list_traits
// {
//     typedef
//         typename detail::is_random_access< VertexListS >::type is_rand_access;
//     typedef typename DirectedS::is_bidir_t is_bidir;
//     typedef typename DirectedS::is_directed_t is_directed;

//     typedef typename mpl::if_< is_bidir, bidirectional_tag,
//         typename mpl::if_< is_directed, directed_tag,
//             undirected_tag >::type >::type directed_category;

//     typedef typename parallel_edge_traits< OutEdgeListS >::type
//         edge_parallel_category;

//     typedef std::size_t vertices_size_type;
//     typedef void* vertex_ptr;
//     typedef typename mpl::if_< is_rand_access, vertices_size_type,
//         vertex_ptr >::type vertex_descriptor;
//     typedef detail::edge_desc_impl< directed_category, vertex_descriptor >
//         edge_descriptor;

// private:
//     // Logic to figure out the edges_size_type
//     struct dummy
//     {
//     };
//     typedef typename container_gen< EdgeListS, dummy >::type EdgeContainer;
//     typedef typename DirectedS::is_bidir_t BidirectionalT;
//     typedef typename DirectedS::is_directed_t DirectedT;
//     typedef typename mpl::and_< DirectedT,
//         typename mpl::not_< BidirectionalT >::type >::type on_edge_storage;

// public:
//     typedef typename mpl::if_< on_edge_storage, std::size_t,
//         typename EdgeContainer::size_type >::type edges_size_type;
// };

// } // namespace boost

// #include <boost/graph/detail/adjacency_list.hpp>

// namespace boost
// {

// //===========================================================================
// // The adjacency_list class.
// //

// template < class OutEdgeListS = vecS, // a Sequence or an AssociativeContainer
//     class VertexListS = vecS, // a Sequence or a RandomAccessContainer
//     class DirectedS = directedS, class VertexProperty = no_property,
//     class EdgeProperty = no_property, class GraphProperty = no_property,
//     class EdgeListS = listS >
// class adjacency_list
// : public detail::adj_list_gen<
//       adjacency_list< OutEdgeListS, VertexListS, DirectedS, VertexProperty,
//           EdgeProperty, GraphProperty, EdgeListS >,
//       VertexListS, OutEdgeListS, DirectedS, VertexProperty, EdgeProperty,
//       GraphProperty, EdgeListS >::type,
//   // Support for named vertices
//   public graph::maybe_named_graph<
//       adjacency_list< OutEdgeListS, VertexListS, DirectedS, VertexProperty,
//           EdgeProperty, GraphProperty, EdgeListS >,
//       typename adjacency_list_traits< OutEdgeListS, VertexListS, DirectedS,
//           EdgeListS >::vertex_descriptor,
//       VertexProperty >
// {
// public:
//     typedef GraphProperty graph_property_type;
//     typedef typename lookup_one_property< GraphProperty, graph_bundle_t >::type
//         graph_bundled;

//     typedef VertexProperty vertex_property_type;
//     typedef
//         typename lookup_one_property< VertexProperty, vertex_bundle_t >::type
//             vertex_bundled;

//     typedef EdgeProperty edge_property_type;
//     typedef typename lookup_one_property< EdgeProperty, edge_bundle_t >::type
//         edge_bundled;

// private:
//     typedef adjacency_list self;
//     typedef typename detail::adj_list_gen< self, VertexListS, OutEdgeListS,
//         DirectedS, vertex_property_type, edge_property_type, GraphProperty,
//         EdgeListS >::type Base;

// public:
//     typedef typename Base::stored_vertex stored_vertex;
//     typedef typename Base::vertices_size_type vertices_size_type;
//     typedef typename Base::edges_size_type edges_size_type;
//     typedef typename Base::degree_size_type degree_size_type;
//     typedef typename Base::vertex_descriptor vertex_descriptor;
//     typedef typename Base::edge_descriptor edge_descriptor;
//     typedef OutEdgeListS out_edge_list_selector;
//     typedef VertexListS vertex_list_selector;
//     typedef DirectedS directed_selector;
//     typedef EdgeListS edge_list_selector;

//     adjacency_list(const GraphProperty& p = GraphProperty())
//     : m_property(new graph_property_type(p))
//     {
//     }

//     adjacency_list(const adjacency_list& x)
//     : Base(x), m_property(new graph_property_type(*x.m_property))
//     {
//     }

//     adjacency_list& operator=(const adjacency_list& x)
//     {
//         // TBD: probably should give the strong guarantee
//         if (&x != this)
//         {
//             Base::operator=(x);

//             // Copy/swap the ptr since we can't just assign it...
//             property_ptr p(new graph_property_type(*x.m_property));
//             m_property.swap(p);
//         }
//         return *this;
//     }

//     // Required by Mutable Graph
//     adjacency_list(vertices_size_type num_vertices,
//         const GraphProperty& p = GraphProperty())
//     : Base(num_vertices), m_property(new graph_property_type(p))
//     {
//     }

//     // Required by Iterator Constructible Graph
//     template < class EdgeIterator >
//     adjacency_list(EdgeIterator first, EdgeIterator last, vertices_size_type n,
//         edges_size_type = 0, const GraphProperty& p = GraphProperty())
//     : Base(n, first, last), m_property(new graph_property_type(p))
//     {
//     }

//     template < class EdgeIterator, class EdgePropertyIterator >
//     adjacency_list(EdgeIterator first, EdgeIterator last,
//         EdgePropertyIterator ep_iter, vertices_size_type n, edges_size_type = 0,
//         const GraphProperty& p = GraphProperty())
//     : Base(n, first, last, ep_iter), m_property(new graph_property_type(p))
//     {
//     }

//     void swap(adjacency_list& x)
//     {
//         // Is there a more efficient way to do this?
//         adjacency_list tmp(x);
//         x = *this;
//         *this = tmp;
//     }

//     void clear()
//     {
//         this->clearing_graph();
//         Base::clear();
//     }

// #ifndef BOOST_GRAPH_NO_BUNDLED_PROPERTIES
//     // Directly access a vertex or edge bundle
//     vertex_bundled& operator[](vertex_descriptor v)
//     {
//         return get(vertex_bundle, *this)[v];
//     }

//     const vertex_bundled& operator[](vertex_descriptor v) const
//     {
//         return get(vertex_bundle, *this)[v];
//     }

//     edge_bundled& operator[](edge_descriptor e)
//     {
//         return get(edge_bundle, *this)[e];
//     }

//     const edge_bundled& operator[](edge_descriptor e) const
//     {
//         return get(edge_bundle, *this)[e];
//     }

//     graph_bundled& operator[](graph_bundle_t) { return get_property(*this); }

//     graph_bundled const& operator[](graph_bundle_t) const
//     {
//         return get_property(*this);
//     }
// #endif

//     //  protected:  (would be protected if friends were more portable)
//     typedef scoped_ptr< graph_property_type > property_ptr;
//     property_ptr m_property;
// };

// #define ADJLIST_PARAMS                                               \
//     typename OEL, typename VL, typename D, typename VP, typename EP, \
//         typename GP, typename EL
// #define ADJLIST adjacency_list< OEL, VL, D, VP, EP, GP, EL >

// template < ADJLIST_PARAMS, typename Tag, typename Value >
// inline void set_property(ADJLIST& g, Tag tag, Value const& value)
// {
//     get_property_value(*g.m_property, tag) = value;
// }

// template < ADJLIST_PARAMS, typename Tag >
// inline typename graph_property< ADJLIST, Tag >::type& get_property(
//     ADJLIST& g, Tag tag)
// {
//     return get_property_value(*g.m_property, tag);
// }

// template < ADJLIST_PARAMS, typename Tag >
// inline typename graph_property< ADJLIST, Tag >::type const& get_property(
//     ADJLIST const& g, Tag tag)
// {
//     return get_property_value(*g.m_property, tag);
// }

// // dwa 09/25/00 - needed to be more explicit so reverse_graph would work.
// template < class Directed, class Vertex, class OutEdgeListS, class VertexListS,
//     class DirectedS, class VertexProperty, class EdgeProperty,
//     class GraphProperty, class EdgeListS >
// inline Vertex source(const detail::edge_base< Directed, Vertex >& e,
//     const adjacency_list< OutEdgeListS, VertexListS, DirectedS, VertexProperty,
//         EdgeProperty, GraphProperty, EdgeListS >&)
// {
//     return e.m_source;
// }

// template < class Directed, class Vertex, class OutEdgeListS, class VertexListS,
//     class DirectedS, class VertexProperty, class EdgeProperty,
//     class GraphProperty, class EdgeListS >
// inline Vertex target(const detail::edge_base< Directed, Vertex >& e,
//     const adjacency_list< OutEdgeListS, VertexListS, DirectedS, VertexProperty,
//         EdgeProperty, GraphProperty, EdgeListS >&)
// {
//     return e.m_target;
// }

// // Mutability Traits
// template < ADJLIST_PARAMS > struct graph_mutability_traits< ADJLIST >
// {
//     typedef mutable_property_graph_tag category;
// };

// // Can't remove vertices from adjacency lists with VL==vecS
// template < typename OEL, typename D, typename VP, typename EP, typename GP,
//     typename EL >
// struct graph_mutability_traits< adjacency_list< OEL, vecS, D, VP, EP, GP, EL > >
// {
//     typedef add_only_property_graph_tag category;
// };
// #undef ADJLIST_PARAMS
// #undef ADJLIST

// } // namespace boost

// #endif // BOOST_GRAPH_ADJACENCY_LIST_HPP

// //=======================================================================
// // Copyright 1997, 1998, 1999, 2000 University of Notre Dame.
// // Authors: Andrew Lumsdaine, Lie-Quan Lee, Jeremy G. Siek
// //
// // Distributed under the Boost Software License, Version 1.0. (See
// // accompanying file LICENSE_1_0.txt or copy at
// // http://www.boost.org/LICENSE_1_0.txt)
// //=======================================================================

// #ifndef BOOST_GRAPH_TRAITS_HPP
// #define BOOST_GRAPH_TRAITS_HPP

// #include <boost/config.hpp>
// #include <iterator>
// #include <utility> /* Primarily for std::pair */
// #include <boost/tuple/tuple.hpp>
// #include <boost/mpl/if.hpp>
// #include <boost/mpl/eval_if.hpp>
// #include <boost/mpl/bool.hpp>
// #include <boost/mpl/not.hpp>
// #include <boost/mpl/has_xxx.hpp>
// #include <boost/mpl/void.hpp>
// #include <boost/mpl/identity.hpp>
// #include <boost/type_traits/is_same.hpp>
// #include <boost/iterator/iterator_categories.hpp>
// #include <boost/iterator/iterator_adaptor.hpp>
// #include <boost/pending/property.hpp>
// #include <boost/detail/workaround.hpp>

// namespace boost
// {

// namespace detail
// {
// #define BOOST_GRAPH_MEMBER_OR_VOID(name)                                                                                            \
//     BOOST_MPL_HAS_XXX_TRAIT_DEF(name)                                                                                               \
//     template < typename T > struct BOOST_JOIN(get_member_, name)                                                                    \
//     {                                                                                                                               \
//         typedef typename T::name type;                                                                                              \
//     };                                                                                                                              \
//     template < typename T >                                                                                                         \
//     struct BOOST_JOIN(get_opt_member_, name)                                                                                        \
//     : boost::mpl::eval_if_c< BOOST_JOIN(has_, name) < T >::value, BOOST_JOIN(get_member_, name)< T >, boost::mpl::identity< void > >\
//     {                                                                                                                               \
//     };
//     BOOST_GRAPH_MEMBER_OR_VOID(adjacency_iterator)
//     BOOST_GRAPH_MEMBER_OR_VOID(out_edge_iterator)
//     BOOST_GRAPH_MEMBER_OR_VOID(in_edge_iterator)
//     BOOST_GRAPH_MEMBER_OR_VOID(vertex_iterator)
//     BOOST_GRAPH_MEMBER_OR_VOID(edge_iterator)
//     BOOST_GRAPH_MEMBER_OR_VOID(vertices_size_type)
//     BOOST_GRAPH_MEMBER_OR_VOID(edges_size_type)
//     BOOST_GRAPH_MEMBER_OR_VOID(degree_size_type)
// }

// template < typename G > struct graph_traits
// {
// #define BOOST_GRAPH_PULL_OPT_MEMBER(name) \
//     typedef typename detail::BOOST_JOIN(get_opt_member_, name)< G >::type name;

//     typedef typename G::vertex_descriptor vertex_descriptor;
//     typedef typename G::edge_descriptor edge_descriptor;
//     BOOST_GRAPH_PULL_OPT_MEMBER(adjacency_iterator)
//     BOOST_GRAPH_PULL_OPT_MEMBER(out_edge_iterator)
//     BOOST_GRAPH_PULL_OPT_MEMBER(in_edge_iterator)
//     BOOST_GRAPH_PULL_OPT_MEMBER(vertex_iterator)
//     BOOST_GRAPH_PULL_OPT_MEMBER(edge_iterator)

//     typedef typename G::directed_category directed_category;
//     typedef typename G::edge_parallel_category edge_parallel_category;
//     typedef typename G::traversal_category traversal_category;

//     BOOST_GRAPH_PULL_OPT_MEMBER(vertices_size_type)
//     BOOST_GRAPH_PULL_OPT_MEMBER(edges_size_type)
//     BOOST_GRAPH_PULL_OPT_MEMBER(degree_size_type)
// #undef BOOST_GRAPH_PULL_OPT_MEMBER

//     static inline vertex_descriptor null_vertex();
// };

// template < typename G >
// inline typename graph_traits< G >::vertex_descriptor
// graph_traits< G >::null_vertex()
// {
//     return G::null_vertex();
// }

// // directed_category tags
// struct directed_tag
// {
// };
// struct undirected_tag
// {
// };
// struct bidirectional_tag : public directed_tag
// {
// };

// namespace detail
// {
//     inline bool is_directed(directed_tag) { return true; }
//     inline bool is_directed(undirected_tag) { return false; }
// }

// /** Return true if the given graph is directed. */
// template < typename Graph > bool is_directed(const Graph&)
// {
//     typedef typename graph_traits< Graph >::directed_category Cat;
//     return detail::is_directed(Cat());
// }

// /** Return true if the given graph is undirected. */
// template < typename Graph > bool is_undirected(const Graph& g)
// {
//     return !is_directed(g);
// }

// /** @name Directed/Undirected Graph Traits */
// //@{
// namespace graph_detail
// {
//     template < typename Tag >
//     struct is_directed_tag
//     : mpl::bool_< is_convertible< Tag, directed_tag >::value >
//     {
//     };
// } // namespace graph_detail

// template < typename Graph >
// struct is_directed_graph
// : graph_detail::is_directed_tag<
//       typename graph_traits< Graph >::directed_category >
// {
// };

// template < typename Graph >
// struct is_undirected_graph : mpl::not_< is_directed_graph< Graph > >
// {
// };
// //@}

// // edge_parallel_category tags
// struct allow_parallel_edge_tag
// {
// };
// struct disallow_parallel_edge_tag
// {
// };

// namespace detail
// {
//     inline bool allows_parallel(allow_parallel_edge_tag) { return true; }
//     inline bool allows_parallel(disallow_parallel_edge_tag) { return false; }
// }

// template < typename Graph > bool allows_parallel_edges(const Graph&)
// {
//     typedef typename graph_traits< Graph >::edge_parallel_category Cat;
//     return detail::allows_parallel(Cat());
// }

// /** @name Parallel Edges Traits */
// //@{
// /**
//  * The is_multigraph metafunction returns true if the graph allows
//  * parallel edges. Technically, a multigraph is a simple graph that
//  * allows parallel edges, but since there are no traits for the allowance
//  * or disallowance of loops, this is a moot point.
//  */
// template < typename Graph >
// struct is_multigraph
// : mpl::bool_< is_same< typename graph_traits< Graph >::edge_parallel_category,
//       allow_parallel_edge_tag >::value >
// {
// };
// //@}

// // traversal_category tags
// struct incidence_graph_tag
// {
// };
// struct adjacency_graph_tag
// {
// };
// struct bidirectional_graph_tag : virtual incidence_graph_tag
// {
// };
// struct vertex_list_graph_tag
// {
// };
// struct edge_list_graph_tag
// {
// };
// struct adjacency_matrix_tag
// {
// };

// // Parallel traversal_category tags
// struct distributed_graph_tag
// {
// };
// struct distributed_vertex_list_graph_tag
// {
// };
// struct distributed_edge_list_graph_tag
// {
// };
// #define BOOST_GRAPH_SEQUENTIAL_TRAITS_DEFINES_DISTRIBUTED_TAGS // Disable these
//                                                                // from external
//                                                                // versions of
//                                                                // PBGL

// /** @name Traversal Category Traits
//  * These traits classify graph types by their supported methods of
//  * vertex and edge traversal.
//  */
// //@{
// template < typename Graph >
// struct is_incidence_graph
// : mpl::bool_<
//       is_convertible< typename graph_traits< Graph >::traversal_category,
//           incidence_graph_tag >::value >
// {
// };

// template < typename Graph >
// struct is_bidirectional_graph
// : mpl::bool_<
//       is_convertible< typename graph_traits< Graph >::traversal_category,
//           bidirectional_graph_tag >::value >
// {
// };

// template < typename Graph >
// struct is_vertex_list_graph
// : mpl::bool_<
//       is_convertible< typename graph_traits< Graph >::traversal_category,
//           vertex_list_graph_tag >::value >
// {
// };

// template < typename Graph >
// struct is_edge_list_graph
// : mpl::bool_<
//       is_convertible< typename graph_traits< Graph >::traversal_category,
//           edge_list_graph_tag >::value >
// {
// };

// template < typename Graph >
// struct is_adjacency_matrix
// : mpl::bool_<
//       is_convertible< typename graph_traits< Graph >::traversal_category,
//           adjacency_matrix_tag >::value >
// {
// };
// //@}

// /** @name Directed Graph Traits
//  * These metafunctions are used to fully classify directed vs. undirected
//  * graphs. Recall that an undirected graph is also bidirectional, but it
//  * cannot be both undirected and directed at the same time.
//  */
// //@{
// template < typename Graph >
// struct is_directed_unidirectional_graph
// : mpl::and_< is_directed_graph< Graph >,
//       mpl::not_< is_bidirectional_graph< Graph > > >
// {
// };

// template < typename Graph >
// struct is_directed_bidirectional_graph
// : mpl::and_< is_directed_graph< Graph >, is_bidirectional_graph< Graph > >
// {
// };
// //@}

// //?? not the right place ?? Lee
// typedef boost::forward_traversal_tag multi_pass_input_iterator_tag;

// namespace detail
// {
//     BOOST_MPL_HAS_XXX_TRAIT_DEF(graph_property_type)
//     BOOST_MPL_HAS_XXX_TRAIT_DEF(edge_property_type)
//     BOOST_MPL_HAS_XXX_TRAIT_DEF(vertex_property_type)

//     template < typename G > struct get_graph_property_type
//     {
//         typedef typename G::graph_property_type type;
//     };
//     template < typename G > struct get_edge_property_type
//     {
//         typedef typename G::edge_property_type type;
//     };
//     template < typename G > struct get_vertex_property_type
//     {
//         typedef typename G::vertex_property_type type;
//     };
// }

// template < typename G >
// struct graph_property_type
// : boost::mpl::eval_if< detail::has_graph_property_type< G >,
//       detail::get_graph_property_type< G >, no_property >
// {
// };
// template < typename G >
// struct edge_property_type
// : boost::mpl::eval_if< detail::has_edge_property_type< G >,
//       detail::get_edge_property_type< G >, no_property >
// {
// };
// template < typename G >
// struct vertex_property_type
// : boost::mpl::eval_if< detail::has_vertex_property_type< G >,
//       detail::get_vertex_property_type< G >, no_property >
// {
// };

// template < typename G > struct graph_bundle_type
// {
//     typedef typename G::graph_bundled type;
// };

// template < typename G > struct vertex_bundle_type
// {
//     typedef typename G::vertex_bundled type;
// };

// template < typename G > struct edge_bundle_type
// {
//     typedef typename G::edge_bundled type;
// };

// namespace graph
// {
//     namespace detail
//     {
//         template < typename Graph, typename Descriptor > class bundled_result
//         {
//             typedef typename graph_traits< Graph >::vertex_descriptor Vertex;
//             typedef typename mpl::if_c< (is_same< Descriptor, Vertex >::value),
//                 vertex_bundle_type< Graph >, edge_bundle_type< Graph > >::type
//                 bundler;

//         public:
//             typedef typename bundler::type type;
//         };

//         template < typename Graph >
//         class bundled_result< Graph, graph_bundle_t >
//         {
//             typedef typename graph_traits< Graph >::vertex_descriptor Vertex;
//             typedef graph_bundle_type< Graph > bundler;

//         public:
//             typedef typename bundler::type type;
//         };

//     }
// } // namespace graph::detail

// namespace graph_detail
// {
//     // A helper metafunction for determining whether or not a type is
//     // bundled.
//     template < typename T >
//     struct is_no_bundle : mpl::bool_< is_same< T, no_property >::value >
//     {
//     };
// } // namespace graph_detail

// /** @name Graph Property Traits
//  * These metafunctions (along with those above), can be used to access the
//  * vertex and edge properties (bundled or otherwise) of vertices and
//  * edges.
//  */
// //@{
// template < typename Graph >
// struct has_graph_property
// : mpl::not_< typename detail::is_no_property<
//       typename graph_property_type< Graph >::type >::type >::type
// {
// };

// template < typename Graph >
// struct has_bundled_graph_property
// : mpl::not_<
//       graph_detail::is_no_bundle< typename graph_bundle_type< Graph >::type > >
// {
// };

// template < typename Graph >
// struct has_vertex_property
// : mpl::not_< typename detail::is_no_property<
//       typename vertex_property_type< Graph >::type > >::type
// {
// };

// template < typename Graph >
// struct has_bundled_vertex_property
// : mpl::not_<
//       graph_detail::is_no_bundle< typename vertex_bundle_type< Graph >::type > >
// {
// };

// template < typename Graph >
// struct has_edge_property
// : mpl::not_< typename detail::is_no_property<
//       typename edge_property_type< Graph >::type > >::type
// {
// };

// template < typename Graph >
// struct has_bundled_edge_property
// : mpl::not_<
//       graph_detail::is_no_bundle< typename edge_bundle_type< Graph >::type > >
// {
// };
// //@}

// } // namespace boost

// // Since pair is in namespace std, Koenig lookup will find source and
// // target if they are also defined in namespace std.  This is illegal,
// // but the alternative is to put source and target in the global
// // namespace which causes name conflicts with other libraries (like
// // SUIF).
// namespace std
// {

// /* Some helper functions for dealing with pairs as edges */
// template < class T, class G > T source(pair< T, T > p, const G&)
// {
//     return p.first;
// }

// template < class T, class G > T target(pair< T, T > p, const G&)
// {
//     return p.second;
// }

// }

// #if defined(__GNUC__) && defined(__SGI_STL_PORT)
// // For some reason g++ with STLport does not see the above definition
// // of source() and target() unless we bring them into the boost
// // namespace.
// namespace boost
// {
// using std::source;
// using std::target;
// }
// #endif

// #endif // BOOST_GRAPH_TRAITS_HPP


// //  Boost config.hpp configuration header file  ------------------------------//

// //  (C) Copyright John Maddock 2002.
// //  Use, modification and distribution are subject to the 
// //  Boost Software License, Version 1.0. (See accompanying file 
// //  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

// //  See http://www.boost.org/libs/config for most recent version.

// //  Boost config.hpp policy and rationale documentation has been moved to
// //  http://www.boost.org/libs/config
// //
// //  CAUTION: This file is intended to be completely stable -
// //           DO NOT MODIFY THIS FILE!
// //

// #ifndef BOOST_CONFIG_HPP
// #define BOOST_CONFIG_HPP

// // if we don't have a user config, then use the default location:
// #if !defined(BOOST_USER_CONFIG) && !defined(BOOST_NO_USER_CONFIG)
// #  define BOOST_USER_CONFIG <boost/config/user.hpp>
// #if 0
// // For dependency trackers:
// #  include <boost/config/user.hpp>
// #endif
// #endif
// // include it first:
// #ifdef BOOST_USER_CONFIG
// #  include BOOST_USER_CONFIG
// #endif

// // if we don't have a compiler config set, try and find one:
// #if !defined(BOOST_COMPILER_CONFIG) && !defined(BOOST_NO_COMPILER_CONFIG) && !defined(BOOST_NO_CONFIG)
// #  include <boost/config/detail/select_compiler_config.hpp>
// #endif
// // if we have a compiler config, include it now:
// #ifdef BOOST_COMPILER_CONFIG
// #  include BOOST_COMPILER_CONFIG
// #endif

// // if we don't have a std library config set, try and find one:
// #if !defined(BOOST_STDLIB_CONFIG) && !defined(BOOST_NO_STDLIB_CONFIG) && !defined(BOOST_NO_CONFIG) && defined(__cplusplus)
// #  include <boost/config/detail/select_stdlib_config.hpp>
// #endif
// // if we have a std library config, include it now:
// #ifdef BOOST_STDLIB_CONFIG
// #  include BOOST_STDLIB_CONFIG
// #endif

// // if we don't have a platform config set, try and find one:
// #if !defined(BOOST_PLATFORM_CONFIG) && !defined(BOOST_NO_PLATFORM_CONFIG) && !defined(BOOST_NO_CONFIG)
// #  include <boost/config/detail/select_platform_config.hpp>
// #endif
// // if we have a platform config, include it now:
// #ifdef BOOST_PLATFORM_CONFIG
// #  include BOOST_PLATFORM_CONFIG
// #endif

// // get config suffix code:
// #include <boost/config/detail/suffix.hpp>

// #ifdef BOOST_HAS_PRAGMA_ONCE
// #pragma once
// #endif

// #endif  // BOOST_CONFIG_HPP


// using namespace boost;

// std::vector<int> p, rk;

// long long res;

// int getp(int v){
//     if (v == p[v]){
//         return v;
//     }

//     return p[v] = getp(p[v]);
// }

// long long get(int cnt){
//     return cnt * 1ll * (cnt - 1) / 2;
// }

// void merge(int u, int v){
//     u = getp(u);
//     v = getp(v);

//     if (rk[u] < rk[v]){
//         swap(u, v);
//     }

//     res -= get(rk[u]);
//     res -= get(rk[v]);

//     rk[u] += rk[v];

//     res += get(rk[u]);

//     p[v] = u;
// }

// int main() {

//     int n;
//     int m;
//     std::cin >> n >> m;

    
//     res = 0;
// 	p = rk = std::vector<int>(n, 1);
// 	std::iota(p.begin(), p.end(), 0);

//     typedef adjacency_list<listS, vecS, bidirectionalS, no_property, property<edge_weight_t, int>> Graph;
//     typedef std::pair<int, int> Edge;
//     typedef graph_traits<Graph>::vertex_descriptor Vertex;
//     typedef property_map<Graph, vertex_index_t>::type IndexMap;
//     typedef property_map<Graph, edge_weight_t>::type WeightMap;
//     typedef graph_traits<Graph>::vertex_iterator vertex_iter;

//     const int num_vertices = n;

//     Edge edges[n-1];
//     int weights[n-1];

//     // add the edges to the graph object
//     for (int i = 0; i < n - 1; ++i){
//         int u, v, w;
//         std::cin >> u >> v >> w;

//         edges[i] = Edge(u - 1, v - 1);
//         weights[i] = w;
//     }

//     Graph g(edges, edges + sizeof(edges) / sizeof(Edge), weights, num_vertices);

//     std::vector<std::pair<int, int>> queries(m);
    
//     for (int j = 0; j < m; j++){
//         std::cin >> queries[j].first;
//         queries[j].second = j;
//     }

//     // int pos = 0; 
//     graph_traits<Graph>::edge_iterator ei, ei_end;
//     // boost::tie(ei, ei_end) = boost::edges(g);
//     IndexMap index = get(vertex_index, g);
//     WeightMap wm = get(edge_weight, g);
//     std::vector<long long> ans(m);


//     std::vector<std::pair<int, std::pair<int,int>>> edge_map;

//     for (boost::tie(ei, ei_end) = boost::edges(g); ei != ei_end; ++ei){
//         std::pair<int, Edge> ed;
//         ed.first = wm[*ei];
//         ed.second = Edge(index[source(*ei, g)], index[target(*ei, g)]);
//         edge_map.push_back(ed);
//     }

//     std::sort(queries.begin(), queries.end());
//     std::sort(edge_map.begin(), edge_map.end());

//     int pos = 0;
//     for (int i =0; i < m; i++){
//         while(pos < n-1 && edge_map.at(pos).first <= queries[i].first){
//             int u = edge_map.at(pos).second.first;
//             int v = edge_map.at(pos).second.second;
//             merge(u, v);
//             ++pos;
//         }
//         ans[queries[i].second] = res;
//     }

//     for (int i =0; i < m; ++i){
//         std::cout << ans[i] << " ";
//     }

//     std::cout << std::endl;

//     return 0;
// }

