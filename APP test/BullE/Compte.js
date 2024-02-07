import React, { useState, useEffect } from 'react';
import { View, Text, TextInput, TouchableOpacity, StyleSheet, ScrollView, Alert } from 'react-native';
import AsyncStorage from '@react-native-async-storage/async-storage';

function GroupDetailsScreen({ route }) {
    const { group } = route.params;
    const [amount, setAmount] = useState('');
    const [amounts, setAmounts] = useState([]);
    const [total, setTotal] = useState(0);

    useEffect(() => {
        const loadAmounts = async () => {
            try {
                const storedAmounts = await AsyncStorage.getItem(`amounts_${group.title}`);
                if (storedAmounts) {
                    const parsedAmounts = JSON.parse(storedAmounts).map(Number);
                    setAmounts(parsedAmounts);
                    setTotal(parsedAmounts.reduce((acc, current) => acc + current, 0));
                }
            } catch (e) {
                Alert.alert("Erreur de chargement", "Impossible de charger les données sauvegardées.");
            }
        };

        loadAmounts();
    }, [group.title]);

    const handleAddAmount = async () => {
        const numericAmount = parseFloat(amount);
        if (!isNaN(numericAmount) && numericAmount > 0) {
            const updatedAmounts = [...amounts, numericAmount];
            setAmounts(updatedAmounts);
            setTotal(updatedAmounts.reduce((acc, current) => acc + current, 0));
            await AsyncStorage.setItem(`amounts_${group.title}`, JSON.stringify(updatedAmounts));
            setAmount('');
        } else {
            Alert.alert("Erreur", "Veuillez entrer un nombre valide.");
        }
    };

    return (
        <View style={styles.container}>
            <Text style={styles.total}>Total: {total.toFixed(2)} €</Text>
            <ScrollView style={styles.amountsList}>
                {amounts.map((item, index) => (
                    <Text key={index} style={styles.amountItem}>
                        {item.toFixed(2)} €
                    </Text>
                ))}
            </ScrollView>
            <Text style={styles.title}>{group.title}</Text>
            <TextInput
                style={styles.input}
                value={amount}
                onChangeText={setAmount}
                placeholder="Entrez un montant"
                placeholderTextColor="grey"
                keyboardType="numeric"
                returnKeyType="done"
            />
            <TouchableOpacity style={styles.addButton} onPress={handleAddAmount}>
                <Text style={styles.addButtonText}>Ajouter</Text>
            </TouchableOpacity>
        </View>
    );
}

const styles = StyleSheet.create({
    container: {
        flex: 1,
        backgroundColor: '#202020',
    },
    amountsList: {
        flex: 1,
    },
    amountItem: {
        fontSize: 16,
        color: 'white',
        padding: 10,
        borderBottomWidth: 1,
        borderBottomColor: 'grey',
    },
    total: {
        color: 'white',
        fontSize: 18,
        fontWeight: 'bold',
        marginVertical: 10,
        alignSelf: 'center',
    },
    title: {
        fontSize: 22,
        color: 'white',
        fontWeight: 'bold',
        textAlign: 'center',
        marginVertical: 20,
    },
    input: {
        color: 'white',
        borderBottomColor: 'white',
        borderBottomWidth: 1,
        margin: 20,
        paddingVertical: 5,
        fontSize: 18,
        textAlign: 'center',
    },
    addButton: {
        backgroundColor: '#e91e63',
        borderRadius: 30,
        paddingVertical: 10,
        paddingHorizontal: 20,
        alignItems: 'center',
        justifyContent: 'center',
        marginHorizontal: 20,
        marginBottom: 20,
    },
    addButtonText: {
        color: 'white',
        fontSize: 16,
        fontWeight: 'bold',
    },
});

export default GroupDetailsScreen;
