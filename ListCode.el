'(this list
       looks like this)

(+ 2 2 2 2 2 2)
(* 2 2 2)

(This is a unquoted list)

'(Here is something for adding.)

fill-column

;;There is a somewhat complex example that to show message function and constuct of Lisp code.
(message "He saw %d %s"
	 (- fill-column 32)
	 (concat "red "
		  (substring 
		   "The quick brown foxes jumped." 16 21)
		  " leaping."))

;;Think about of the scope of variables in Emacs Lisp language.
;;Here an example for a counter.
;;Here is what confused that is the difference of the life cycle of variables between C language and Emacs  Lisp language.???
(setq counter 0)
(setq counter (+ counter 1))
counter

;;1.11 exercises
(ccc) ;;void function
ccc ;;void variable

;;sections 2--Practicing Evaluation
;;And there is a question that is how to type build-functions correctly and completely.???
(buffer-name) ;;the buffer name
(buffer-file-name) ;; the full path-name of the file.

;;2.5 exercise
;;Find a file with which you are working and move towards its middle. Find Its buffer name, file name, length, and your position int the buffer.
(message (buffer-name))
(message (buffer-file-name))
(message (number-to-string (buffer-size)))
(message (number-to-string (point)))

;;move towards its middle.
;;There is another question that is how refer to manual of some special function like move-column.?
;;And how to comment a line quickly in somewhere.?C-x and C-;?but failed.
(point-min)
(point-max)
;;How to excute several line of Emacs Lisp together at the same time.?
(backward-char (/ (point-max) 2))
;sldkfjlsdkf

;;Important part of Emacs Lisp.
;;The let of Emacs Lisp.
;;The template for let expression.
(let (thread 
      (needles 3)
      (another_value 10)
      ...)
  body...)
;;When you write let expression, what you do is put the appropriate expressions in
;;the slots of the let expression template.

;;The if expression form.
(if ture-or-false-test
    action-carry-out-if-test-is-true
  action-carry-out-if-test-retuns-false)
;;When yo do wirte if expresion, what you do is put the appropriate expressions in
;;the slots of the if expression template.
