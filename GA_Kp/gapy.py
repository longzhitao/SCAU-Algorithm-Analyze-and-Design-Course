import random as rd
import copy
import xlrd


class GA(object):
    weight = list()
    value = list()
    C = 0

    def __init__(self, population, gene_length, mutation_rate, recombination_rate, c):
        self.population = population
        self.gene_length = gene_length
        self.C = c

        self.mutation_rate = mutation_rate
        self.recombination_rate = recombination_rate

        self.gene_list = list()
        self.gene_fitness_var = list()

        self.best_gene = None
        self.best_gene_fitness_var = 0

        while True:
            self.gene_list.clear()
            for i in range(self.population):
                gene = list()
                for j in range(self.gene_length):
                    rand = rd.random()
                    if rand >= 0.8:
                        gene.append('1')
                    else:
                        gene.append('0')
                self.gene_list.append(gene)
            self.fitness_func()
            if self.best_gene_fitness_var > 0:
                break

    def fitness_func(self):
        self.gene_fitness_var.clear()
        for i in range(self.population):
            fitness_var = 0
            total_weight = 0

            for j in range(self.gene_length):
                if self.gene_list[i][j] == '1':
                    fitness_var += int(self.value[j])
                    total_weight += int(self.weight[j])

                if total_weight > self.C:
                    fitness_var = 0

            if fitness_var > self.best_gene_fitness_var:
                self.best_gene = self.gene_list[i]
                self.best_gene_fitness_var = fitness_var

            self.gene_fitness_var.append(fitness_var)

    def roulette_wheel_selection(self):
        sum_fitness_var = sum(self.gene_fitness_var)
        total_probability = 0
        rand = rd.random()
        select_index = 0
        for i in range(self.population):
            total_probability = total_probability + self.gene_fitness_var[i] / sum_fitness_var
            if total_probability >= rand:
                select_index = i
                break
        return select_index

    @staticmethod
    def operation_selection(probability):
        rand = rd.random()
        if rand <= probability:
            return True
        else:
            return False

    def evolution(self):
        select_index = self.roulette_wheel_selection()
        gene_copy = copy.deepcopy(self.gene_list[select_index])

        # mutation
        if self.operation_selection(self.mutation_rate):
            mutation_pos = rd.randint(0, self.gene_length - 1)
            if gene_copy[mutation_pos] == '1':
                gene_copy[mutation_pos] = '0'
            else:
                gene_copy[mutation_pos] = '1'

        # recombination
        if self.operation_selection(self.recombination_rate):
            first_pos = rd.randint(0, self.gene_length - 1)
            last_pos = rd.randint(first_pos, self.gene_length)
            another_gene = self.gene_list[self.roulette_wheel_selection()]
            gene_copy[first_pos: last_pos] = another_gene[first_pos: last_pos]

        return gene_copy

    def generate_offspring(self):
        offspring = list()
        for i in range(self.population - 1):
            offspring.append(self.evolution())
        offspring.append(copy.deepcopy(self.best_gene))
        self.gene_list = offspring
        self.fitness_func()
        pass

    def display(self):
        for i in range(self.population):
            print(''.join(self.gene_list[i]), end=' ')
            print('value: ' + str(self.gene_fitness_var[i]))
        print('---------------------------------------------')
        print('Best Gene:')
        print(''.join(self.best_gene), end=' ')
        print('value: ' + str(self.best_gene_fitness_var))

    def run(self, max_generation):
        generation = 1
        for i in range(max_generation):
            print('No. ' + str(generation + i) + ' generation')
            self.display()

            self.generate_offspring()

            if self.best_gene_fitness_var == 1063:
                break


if __name__ == '__main__':
    wb = xlrd.open_workbook(filename='0-1背包问题测试数据（提供参考）.xls')
    sheet1 = wb.sheet_by_index(0)
    list1 = sheet1.col_values(0, 5)
    weight = list()
    value = list()
    for k in range(50):
        split_list = list1[k].split(' ')
        weight.append(split_list[0])
        value.append(split_list[1])
    GA.weight = weight
    GA.value = value

    ga = GA(100, 50, 0.2, 0, 300)
    ga.run(300)
    pass
