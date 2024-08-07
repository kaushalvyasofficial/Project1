class Student:
    def __init__(self, pnr, marks):
        self.pnr = pnr
        self.marks = marks

class HashTable:
    def __init__(self, size):
        self.size = size
        self.table = [None] * size

    def hash_function(self, pnr):
        return pnr % self.size

    def insert_linear_probing(self, student):
        index = self.hash_function(student.pnr)
        while self.table[index] is not None:
            index = (index + 1) % self.size
        self.table[index] = student

    def lookup_linear_probing(self, pnr):
        index = self.hash_function(pnr)
        while self.table[index] is not None:
            if self.table[index].pnr == pnr:
                return self.table[index].marks
            index = (index + 1) % self.size
        return None

    def delete_linear_probing(self, pnr):
        index = self.hash_function(pnr)
        while self.table[index] is not None:
            if self.table[index].pnr == pnr:
                self.table[index] = None
                return
            index = (index + 1) % self.size

    def insert_linear_probing_with_chaining(self, student):
        index = self.hash_function(student.pnr)
        if self.table[index] is None:
            self.table[index] = [student]
        else:
            self.table[index].append(student)

    def lookup_linear_probing_with_chaining(self, pnr):
        index = self.hash_function(pnr)
        if self.table[index] is not None:
            for record in self.table[index]:
                if record.pnr == pnr:
                    return record.marks
        return None

# Example usage:
hash_table = HashTable(10)

# Inserting records
hash_table.insert_linear_probing(Student(123, 85))
hash_table.insert_linear_probing(Student(456, 75))
hash_table.insert_linear_probing(Student(789, 90))

# Lookup
print(hash_table.lookup_linear_probing(123))  # Output: 85
print(hash_table.lookup_linear_probing(456))  # Output: 75
print(hash_table.lookup_linear_probing(999))  # Output: None

# Deleting record
hash_table.delete_linear_probing(123)

# Lookup after deletion
print(hash_table.lookup_linear_probing(123))  # Output: None
