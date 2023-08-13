(define/contract (peak-index-in-mountain-array arr)
  (-> (listof exact-integer?) exact-integer?)

  (define (find-peak low high)
    ;; Binary search to find the peak element
    (let ((mid (quotient (+ low high) 2)))
      (cond
        ((< (list-ref arr mid) (list-ref arr (+ mid 1))) ; If mid element is less than the next element
         (find-peak (+ mid 1) high))
        ((< (list-ref arr mid) (list-ref arr (- mid 1))) ; If mid element is less than the previous element
         (find-peak low (- mid 1)))
        (else mid))))

  (find-peak 0 (- (length arr) 1))) ; Start the search from the entire array range
