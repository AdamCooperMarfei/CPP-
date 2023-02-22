#include<cstddef>
#include<string>

class istream_line_reader
{
private:
    /* data */
    std::istream *stream_;

public:
    istream_line_reader(/* args */)noexcept;
    explicit istream_line_reader(std::istream &is)noexcept;
    ~istream_line_reader();
    class iterator
    {
    private:
        /* data */
        std::istream *stream_;
        std::string line_;
    public:
        typedef std::ptrdiff_t difference_type;
        typedef std::string value_type;
        typedef const value_type*pointer;
        typedef const value_type&reference;
        typedef std::input_iterator_tag iterator_category;
        iterator() noexcept
        : stream_(nullptr) {}
        explicit iterator(std::istream& is)
        : stream_(&is)
        {
            ++*this;
        }
        reference operator*() const noexcept
        {
            return line_;
        }
        pointer operator->() const noexcept
        {
            return &line_;
        }
        iterator& operator++()
        {
            getline(*stream_, line_);
            return *this;
        }
        iterator operator++(int)
        {
            iterator temp(*this);
            ++*this;
            return temp;
        }
        bool operator==(const iterator &rhs)
        const noexcept
        {
            return stream_ == rhs.stream_;
        }
        bool operator!= (const iterator &rhs)
        const noexcept
        {
            return !operator==(rhs);
        }
    };
    iterator begin()
    {
        return iterator(*stream_);
    }
    iterator end()const noexcept
    {
        return iterator();
    }   
};

istream_line_reader::istream_line_reader(/* args */)noexcept
{
    stream_ = nullptr;
}
istream_line_reader::istream_line_reader(std::istream &is)noexcept
{
    stream_ = &is;
}

istream_line_reader::~istream_line_reader()
{
}
