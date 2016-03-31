#ifndef __NODE_H_
#define __NODE_H_

template <typename T>
struct Node {
private:
  T value;
  Node<T> *next, *prev;

public:
  Node();
  Node(T value);
  Node(const Node<T>& n);
  void operator=(const Node<T>& n);

  ~Node();

  T getValue();
  Node<T> *getNext();
  Node<T> *getPrev();
  void setNext(Node<T>* n);
  void setPrev(Node<T>* n);
};

#endif /* __NODE_H_ */
