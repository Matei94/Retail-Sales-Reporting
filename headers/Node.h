#ifndef __NODE_H_
#define __NODE_H_

template <typename T>
struct Node {
private:
  T value;
  Node<T> *next;

public:
  Node();
  Node(T value);
  Node(const Node<T>& n);
  void operator=(const Node<T>& n);

  ~Node();

  T getValue();
  Node<T> *getNext();
  void setNext(Node<T>* n);
};

#endif /* __NODE_H_ */
