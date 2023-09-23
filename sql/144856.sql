-- https://school.programmers.co.kr/learn/courses/30/lessons/144856

SELECT
    A.author_id,
    A.author_name,
    A.category,
    # A.total
    SUM(A.total) as total_sales
    # (A.price * A.sales) as total_salse
FROM
    (
        SELECT 
            b.book_id,
            b.author_id,
            b.category,
            bs.sales_date,
            a.author_name,
            (b.price * bs.sales) as total
        FROM book b
        LEFT JOIN author a ON a.author_id = b.author_id
        LEFT JOIN book_sales bs ON bs.book_id = b.book_id
        WHERE bs.sales_date LIKE '2022-01%'
    ) A
GROUP BY A.author_id, A.category
ORDER BY A.author_id, A.category DESC;