Q.1


-- SET SERVEROUTPUT ON;

DECLARE
   inputNumber VARCHAR2(20) := '12345'; -- Change this to your input number as a string
   invertedNumber VARCHAR2(20) := ''; -- Initialize the inverted number as an empty string
   i NUMBER;

BEGIN
   -- Using a FOR loop
   FOR i IN REVERSE 1..LENGTH(inputNumber) LOOP
      invertedNumber := invertedNumber || SUBSTR(inputNumber, i, 1);
   END LOOP;

   DBMS_OUTPUT.PUT_LINE('Inverted Number using FOR loop: ' || invertedNumber);

   -- Reset the invertedNumber variable
   invertedNumber := '';

   -- Using a WHILE loop
   i := LENGTH(inputNumber);
   WHILE i >= 1 LOOP
      invertedNumber := invertedNumber || SUBSTR(inputNumber, i, 1);
      i := i - 1;
   END LOOP;

   DBMS_OUTPUT.PUT_LINE('Inverted Number using WHILE loop: ' || invertedNumber);

END;
/


Q.2 


-- SET SERVEROUTPUT ON;

DECLARE
   radius NUMBER;
   area NUMBER;
BEGIN
   -- Create the AREAS table if it doesn't exist
   EXECUTE IMMEDIATE 'CREATE TABLE AREAS (Radius NUMBER, Area NUMBER)';

   -- Loop through the range of radii
   FOR radius IN 4..10 LOOP
      -- Calculate the area for the current radius
      area := 3.14159 * POWER(radius, 2); -- Assuming Pi value

      -- Insert the radius and area into the AREAS table
      INSERT INTO AREAS (Radius, Area) VALUES (radius, area);

      -- Display the calculated area
      DBMS_OUTPUT.PUT_LINE('Radius = ' || radius || ', Area = ' || area);
   END LOOP;

   -- Commit the transaction to save the data
   COMMIT;
END;
/



Q.3

-- SET SERVEROUTPUT ON;

DECLARE
   v_sid SAILORS.SID%TYPE;
   v_sname SAILORS.SNAME%TYPE;
   v_rating SAILORS.RATING%TYPE;
   v_age NUMBER;
   v_current_date DATE := SYSDATE; -- Get the current date

BEGIN
   -- Create the HigherRating table if it doesn't exist
   EXECUTE IMMEDIATE 'CREATE TABLE HigherRating AS SELECT * FROM SAILORS WHERE 1 = 0';

   -- Display the header for the output format
   DBMS_OUTPUT.PUT_LINE('----------------------------------------------');
   DBMS_OUTPUT.PUT_LINE('sid sname rating age Date');
   DBMS_OUTPUT.PUT_LINE('----------------------------------------------');

   -- Loop through the sailors in the SAILORS table
   FOR sailor_rec IN (SELECT * FROM SAILORS) LOOP
      v_sid := sailor_rec.SID;
      v_sname := sailor_rec.SNAME;
      v_rating := sailor_rec.RATING;
      v_age := EXTRACT(YEAR FROM v_current_date) - EXTRACT(YEAR FROM sailor_rec.BIRTHDATE); -- Calculate age

      -- Display the sailor information in the specified format
      DBMS_OUTPUT.PUT_LINE(v_sid || ' ' || v_sname || ' ' || v_rating || ' ' || v_age || ' ' || TO_CHAR(v_current_date, 'DD-MON-YYYY'));

      -- Check if the sailor's rating is greater than 7
      IF v_rating > 7 THEN
         -- Insert the sailor into the HigherRating table
         INSERT INTO HigherRating (SID, SNAME, RATING, AGE, Date)
         VALUES (v_sid, v_sname, v_rating, v_age, v_current_date);
      END IF;
   END LOOP;

   -- Display the footer for the output format
   DBMS_OUTPUT.PUT_LINE('----------------------------------------------');

   -- Commit the transaction to save the data
   COMMIT;
END;
/
