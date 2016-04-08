#ifndef __NODE_H_
#define __NODE_H_

template <typename T>
class Node {
  private:
    T value;
    Node<T> *next;

  public:
    /* Constructor Default */
    Node();

    /* Constructor */
    Node(T value);
    
    /* Copy Constructor */
    Node(const Node<T>& nod);

    /* Copy Assignment */
    void operator=(const Node<T>& nod);

    /* Destructor */
    ~Node();

    /* Functia de extragere a valorii value */
    T getValue();

    /* Functia ce returneaza pointer la urmatorul nod */
    Node<T> *getNext();

    /* Functia ce seteaza valoarea nodului curent */
    void setValue(T newValue);

    /* Functia ce seteaza legatura cu urmatorul nod */
    void setNext(Node<T>* nod);
};

#endif /* __NODE_H_ */
