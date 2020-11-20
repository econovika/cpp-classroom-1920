namespace cls_09  {

    template<class It, class T>
    void fill(It begin, It end, const T &val) {
        while (begin != end)
            *(begin++) = val;
    }

    template<class It, class Generator>
    void generate(It begin, It end, const Generator func) {
        while (begin != end)
            *(begin++) = func();
    }

    template<class InputIt, class OutputIt>
    OutputIt copy(InputIt src_beg, InputIt src_end, OutputIt dst_beg) {
        while (src_beg != src_end)
            *(dst_beg++) = *(src_beg++);
        return dst_beg;
    }

    template<class It, class Functor>
    Functor for_each(It begin, It end, Functor functor) {
        while (begin != end)
            functor(*(begin++));
        return functor;
    }
}