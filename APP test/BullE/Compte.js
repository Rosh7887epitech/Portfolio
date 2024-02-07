import React, { useState, useEffect } from 'react';
import { View, Text, TextInput, TouchableOpacity, StyleSheet, ScrollView, Alert } from 'react-native';
import AsyncStorage from '@react-native-async-storage/async-storage';
import { Picker } from '@react-native-picker/picker';

function GroupDetailsScreen({ route }) {
    const { group } = route.params;
    const [amount, setAmount] = useState('');
    const [selectedMember, setSelectedMember] = useState(group.members?.[0]?.id || '');
    const [amounts, setAmounts] = useState([]);
    const [total, setTotal] = useState(0);

    useEffect(() => {
        const loadAmounts = async () => {
            try {
                const storedAmounts = await AsyncStorage.getItem(`amounts_${group.title}`);
                if (storedAmounts) {
                    const parsedAmounts = JSON.parse(storedAmounts);
                    setAmounts(parsedAmounts);
                    setTotal(parsedAmounts.reduce((acc, current) => acc + current.value, 0));
                }
            } catch (e) {
                Alert.alert("Erreur de chargement", "Impossible de charger les données sauvegardées.");
            }
        };
        loadAmounts();
    }, [group.title]);

    const handleAddAmount = async () => {
        const numericAmount = parseFloat(amount);
        if (!isNaN(numericAmount) && numericAmount > 0 && selectedMember) {
            const newAmount = {
                id: Date.now().toString(),
                value: numericAmount,
                paidBy: selectedMember,
            };
            const updatedAmounts = [...amounts, newAmount];
            setAmounts(updatedAmounts);
            setTotal(updatedAmounts.reduce((acc, current) => acc + current.value, 0));
            await AsyncStorage.setItem(`amounts_${group.title}`, JSON.stringify(updatedAmounts));
            setAmount('');
        } else {
            Alert.alert("Erreur", "Veuillez entrer un montant valide et sélectionner un membre.");
        }
    };

    const handleDeleteAmount = async (amountId) => {
        const updatedAmounts = amounts.filter(amount => amount.id !== amountId);
        setAmounts(updatedAmounts);
        setTotal(updatedAmounts.reduce((acc, current) => acc + current.value, 0));
        await AsyncStorage.setItem(`amounts_${group.title}`, JSON.stringify(updatedAmounts));
    };

    return (
        <View style={styles.container}>
            <Text style={styles.total}>Total: {total.toFixed(2)} €</Text>
            <ScrollView style={styles.amountsList}>
                {amounts.map((item, index) => (
                    <View key={item.id} style={styles.amountItemRow}>
                        <Text style={styles.amountItem}>
                            {item.value.toFixed(2)} € - Payé par {
                                group.members.find(member => member.id === item.paidBy)?.name || 'Membre Inconnu'
                            }
                        </Text>
                        <TouchableOpacity onPress={() => handleDeleteAmount(item.id)} style={styles.deleteButton}>
                            <Text style={styles.deleteButtonText}>X</Text>
                        </TouchableOpacity>
                    </View>
                ))}
            </ScrollView>
            <Text style={styles.title}>{group.title}</Text>
            <Picker
                selectedValue={selectedMember}
                style={styles.picker}
                onValueChange={(itemValue, itemIndex) => setSelectedMember(itemValue)}
                mode="dropdown"
            >
                {group.members.map((member) => (
                    <Picker.Item key={member.id} label={member.name} value={member.id} />
                ))}
            </Picker>
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
        borderBottomColor: '#808080',
    },
    amountItemRow: {
        flexDirection: 'row',
        justifyContent: 'space-between',
        alignItems: 'center',
        padding: 10,
    },
    deleteButton: {
        marginLeft: 10,
        backgroundColor: 'white',
        padding: 5,
        borderRadius: 5,
    },
    deleteButtonText: {
        color: 'black',
        fontSize: 12,
        fontWeight: 'bold',
    },
    picker: {
        height: 50,
        width: '100%',
        color: 'black',
        backgroundColor: 'white',
        marginBottom: 20,
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
        backgroundColor: 'white',
        borderRadius: 30,
        paddingVertical: 10,
        paddingHorizontal: 20,
        alignItems: 'center',
        justifyContent: 'center',
        marginHorizontal: 20,
        marginBottom: 20,
    },
    addButtonText: {
        color: 'black',
        fontSize: 16,
        fontWeight: 'bold',
    },
});

export default GroupDetailsScreen;
